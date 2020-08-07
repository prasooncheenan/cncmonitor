#include  <vector>
#include <map>
#include <string>
#include <limits>
#include <functional>

const int TEMPERATURE = 0;
const int VARIATION = 1;
const int TOTALTIME = 2;

static  double currentParameters[3]{ 0.0, 0.0, 0.0 };

const std::string InformationRunning[] = {
	"High Temperature",
	"Parts variation more than 0.05",
	"Machine running for more than 6 hours"
};

const std::string MachineStatus[] = {
	"No data",
	"Controller board in the machine is not ok",
	"Configuration data in the machine is corrupted"
};


class Limits
{
	std::map<int, std::pair<double, double>> _limitMap;

public:
	Limits()
	{
		_limitMap[TEMPERATURE] = std::make_pair(std::numeric_limits<double>::min(), 35);
		_limitMap[VARIATION] = std::make_pair(std::numeric_limits<double>::min(), 0.05);
		_limitMap[TOTALTIME] = std::make_pair(std::numeric_limits<double>::min(), 360);
	}
	std::pair<double, double> GetLimits(int key)
	{
		return _limitMap[key];
	}

	bool SetLimits(int key, std::pair<double, double> limits)
	{
		_limitMap[key] = limits;
	}
};

std::string CheckLimits(int, double);
