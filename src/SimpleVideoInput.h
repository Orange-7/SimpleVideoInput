#pragma once

#include <opencv2/core/core.hpp>

struct SimpleVideoInputDetail;

class SimpleVideoInput 
{
public:
	SimpleVideoInput();
	SimpleVideoInput(const std::string & fileName);
	virtual ~SimpleVideoInput();

	bool open(const std::string & fileName);
	bool isOpened() const;
	void release();

	long millisecondsPerFrame() const;

	SimpleVideoInput & operator>>(cv::Mat & image);
	bool read(cv::Mat & image);

private:
	SimpleVideoInputDetail *m_detail;

	void initLibavcodec();
	void findFirstVideoStream();
	void openCodec();
	void prepareTargetBuffers();
	void fillMat(cv::Mat & image);
};

