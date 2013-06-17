#pragma once

#include <string>

class VideoFlags
{
public:
	enum FSAASamples
	{
		NO_FSAA = 0,
		FSAA_2X = 2,
		FSAA_4X = 4,
		FSAA_8X = 8,
		FSAA_16X = 16,
		FSAA_32X = 32
	};
private:
	FSAASamples _fsaaSamples;
	int _refreshRate;
	bool _resizable;
	std::string _title;
protected:
public:
	VideoFlags();
	static const int DEFAULT_REFRESH_RATE = 0;
	FSAASamples getFSAASamples() const {return _fsaaSamples;}
	void setFSAASamples(FSAASamples fsaa) {_fsaaSamples = fsaa;}
	int getRefreshRate() const {return _refreshRate;}
	void setRefreshRate(int rate) {_refreshRate = rate;}
	void setResizable(bool res) {_resizable = res;}
	bool isResizable() const {return _resizable;}
	const std::string &getTitle() const {return _title;}
	void setTitle(const std::string &title) {_title = title;}
};
