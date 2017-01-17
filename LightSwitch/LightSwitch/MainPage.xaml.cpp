//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace LightSwitch;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Devices::Enumeration;
using namespace Windows::Devices::Gpio;
using namespace concurrency;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();

	initGPIO(); //Initializes the GPIO
	timerOn_ = ref new DispatcherTimer();
	timerOff_ = ref new DispatcherTimer();
	TimeSpan intervalOn, intervalOff;
	intervalOff.Duration = 100;
	intervalOn.Duration = 50;
	timerOn_->Interval = intervalOn;
	timerOff_->Interval = intervalOff;
	timerOn_->Tick += ref new EventHandler<Object ^>(this, &MainPage::OnTickOn);
	timerOff_->Tick += ref new EventHandler<Object ^>(this, &MainPage::OnTickOff);
}

void MainPage::initGPIO() {
	auto gpio = GpioController::GetDefault(); //Selects GPIOController

	LED_pin_ = gpio->OpenPin(LED_PIN); //Opens a connection to the pin to control the LED
	LED_pin_->Write(pinInitValue_);	//Set the initial value to the pin (GpioPinValue::Low)
	LED_pin_->SetDriveMode(GpioPinDriveMode::Output); //Set pin as an output
}

// Name:		switchButton_Click()
// Type:		Void LightSwitch::MainPage
// Parameters:	Platform::Object sender (unused), Windows::UI::Xaml::RoutedEventArgs e (unused)
// usage:		Is called when the light switch button (switchButton) is pressed.
//				if the LED (LED_pin_) is off (GpioPinValue::Low), the LED is turned on (GpioPinValue::High)
//				and the text on the light switch button is changed.
void LightSwitch::MainPage::switchButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (LED_pin_->Read() == GpioPinValue::Low) { //read the current value of the pin
		LED_pin_->Write(GpioPinValue::High); //turn the pin on
		switchButton->Content = "Turn Light Off"; //change the text on the light switch button
	}
	else {
		LED_pin_->Write(GpioPinValue::Low); //turn the pin off
		switchButton->Content = "Turn Light on"; //change the text on the light switch button
	}
	Slider::V
}
