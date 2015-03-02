#pragma once
#include "yBasic.h"
namespace yewbow
{
	class Screen
	{
	public:
		void SetSize(int width, int height,tReal  pixel);
		void SetBuffer(tByte* buffer);
		tByte* GetBuffer(){ return _buffer; }
	private:
		tByte* _buffer;
		int _width;
		int _height;
		tReal _pixelstep;

	};
}