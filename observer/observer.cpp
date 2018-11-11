#include <iostream>
#include <list>
#include "observer.h"

CurrentConditionDisplay::CurrentConditionDisplay(WeatherData *weaterData) {
	weaterData->registerOberver(this);
};

void CurrentConditionDisplay::update(float temperature, float humidity, float pressure) {
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	display();
};

void CurrentConditionDisplay::display() {
	std::cout << "現在の気象状況：　温度"  << temperature << "度　湿度" << humidity << "%" << std::endl;
};

void WeatherData::registerOberver(Observer* o) {
	std::cout << "resister" << std::endl;
	observers.push_back(o);
};

void WeatherData::removeOberver(Observer* o) {
	for(std::list<Observer*>::iterator it = observers.begin(); it != observers.end(); it++) {
		if(*it == o) {
			observers.erase(it);
		}
	}
};

void WeatherData::notifyOberver() {
	for(Observer* o : observers) {
		std::cout << o << std::endl;
		o->update(temperature, humidity, pressure);
	}
};

void WeatherData::mesurementChanged() {
	notifyOberver();
};

void WeatherData::setMesuarements(float temp, float hum, float pres) {
	temperature = temp;
	humidity = hum;
	pressure = pres;
	mesurementChanged();
};

int main() {
	WeatherData *weatherData = new WeatherData();
	CurrentConditionDisplay* crrentDisplay = new CurrentConditionDisplay(weatherData);

	weatherData->setMesuarements(27, 65, 30.4f);
	weatherData->setMesuarements(28, 70, 29.2f);
};