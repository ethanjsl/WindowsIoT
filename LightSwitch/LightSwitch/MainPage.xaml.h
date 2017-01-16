//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace LightSwitch
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void initGPIO(); //GPIO initialization method
		Windows::Devices::Gpio::GpioPinValue pinInitValue_ = Windows::Devices::Gpio::GpioPinValue::Low; //Set the initial value for the LED
		const int LED_PIN = 5; //Use GPIO5 as the LED pin
		Windows::Devices::Gpio::GpioPin ^LED_pin_; //name the LED pin
		void switchButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e); //Method used to detect if the light switch button is pressed
	};
}

/*
Electronical Diagram
GPIO5 ------
			|
			|
		   | |
		   | | 330R
		   | |	
			|
			|
		  ------
		  \	   /
		   \  / \\ Green LED
			\/
		 --------
			|
			|
GND --------
*/