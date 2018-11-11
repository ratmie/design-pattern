#include <iostream>
#include <list>
class Observer {
	public:
	virtual void update(float temperature, float humidity, float pressure) = 0;
};

class WeatherData {
	std::list<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;
	
	public:
	void registerOberver(Observer* o);
	void removeOberver(Observer* o);
	void notifyOberver();
	void mesurementChanged();
	void setMesuarements(float temp, float hum, float pres);
};

class CurrentConditionDisplay : public Observer {
	float temperature;
	float humidity;
	float pressure;

	public:
	CurrentConditionDisplay(WeatherData *weaterData);
	void update(float temperature, float humidity, float pressure);
	void display();
};





