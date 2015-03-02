#include"yScreen.h"
using namespace yewbow;
void Screen::SetSize(int width, int height, tReal  pixel)
{
	_width = width;
	_height = height;
	_pixelstep = pixel;
}
void Screen::SetBuffer(tByte* buffer)
{
	_buffer = buffer;
	MatR4x4 a;

}
