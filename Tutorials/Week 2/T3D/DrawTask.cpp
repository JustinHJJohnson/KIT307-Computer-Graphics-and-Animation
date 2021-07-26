// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// GameObject.cpp
//
// Simple task for drawing to and animating textures, used in tutorial 1 for practice implementing drawing routines

#include <math.h>
#include "Renderer.h"
#include "DrawTask.h"
#include "Logger.h"

namespace T3D 
{
	/*
	 * \param app Application root
	 * \param tex Texture to draw onto
	 *
	 * \note `tex` should be initialised, and registered with the renderer as both a loaded Texture and a 2D Overlay. This can be done using `new Texture(...)`, `loadTexture(...)`, and finally `add2DOverlay(...)`.
	 * \note If nothing is drawing on the screen, ensure the returned DrawTask object is added to the list of Tasks from the callsite using `addTask(...).
	 * \note If there is nothing on the screen still, check the visual studio console for error messages in case something is out of bounds.
	 *
	 */
	DrawTask::DrawTask(T3DApplication *app, Texture* tex) : Task(app)
	{
		drawArea = tex;

		// @BoundsCheck - requires using pushPixel
		// Reserve some space for the buffer, as its unlikely only few pixels will be plotted
		// const uint32_t pixelsToReserve = 512;
		// pixelPlotQueue.reserve(pixelsToReserve);

		init();
		logger::Log(priority::Info, output_stream::All, category::Task, "Initialised DrawTask");
	}

	/*
	 * \param 
	 * \note This isn't necessary. It could be inlined into the constructor.
	 */
	void DrawTask::init	(){		
		drawArea->clear(Colour(255,255,255,255));
		drawDDALine(100,100,200,200,Colour(0,0,0,255));
	}

	/*
	 * \param x1 Start x pixel coordinate 
	 * \param y1 Start y pixel coordinate
	 * \param x2 End x pixel coordinate 
	 * \param y2 End y pixel coordinate
	 * \param Colour of line
	 *
	 * \note Uses floating-point numbers as seen in the 2D graphics lecture.
	 * \note `pushPixel` is used to do large batches of *bounds-checked* pixel drawing, which you may prefer to your application crashing if you go outside the texture area.
	 */
	void DrawTask::drawDDALine(int x1, int y1, int x2, int y2, Colour c){
		float y = float(y1);
		float x = float(x1);
		float deltaX = float(x2 - x1);
		float deltaY = float(y2 - y1);

		if (abs(deltaX) > abs(deltaY))
		{
			float dY = deltaY / deltaX;
			
			if (deltaX > 0)
			{
				for (int x = x1; x < x2; x++)
				{
					drawArea->plotPixel(x, int(y), c);
					y += dY;
				}
			}
			else
			{
				for (int x = x1; x > x2; x--)
				{
					drawArea->plotPixel(x, int(y), c);
					y -= dY;
				}
			}
		}
		else
		{
			float dX = deltaX / deltaY;

			if (deltaY > 0)
			{
				for (int y = y1; y < y2; y++)
				{
					drawArea->plotPixel(int(x), y, c);
					x += dX;
				}
			}
			else
			{
				for (int y = y1; y > y2; y--)
				{
					drawArea->plotPixel(int(x), y, c);
					x -= dX;
				}
			}
		}
	}
		

	/*
	 * \param x1 Start x pixel coordinate 
	 * \param y1 Start y pixel coordinate
	 * \param x2 End x pixel coordinate 
	 * \param y2 End y pixel coordinate
	 * \param Colour of line
	 * 
	 * \note UNIMPLEMENTED! That's your job in the tutorials.
	 */
	void DrawTask::drawBresLine(int x1, int y1, int x2, int y2, Colour c)
	{
		int deltay = (y2 - y1);
		int deltax = (x2 - x1);
		int error = deltax / 2;
		int y = y1;
		int x = x1;

		/*for (int x = x1; x <= x2; x++) {
			drawArea->plotPixel(x, y, c);
			error = error - deltay;
			if (error < 0) {
				y += 1;
				error += deltax;
			}
		}*/

		if (abs(deltax) > abs(deltay))
		{
			if (deltax > 0)
			{
				for (int x = x1; x <= x2; x++)
				{
					drawArea->plotPixel(x, y, c);
					error = error - deltay;
					if (error < 0)
					{
						y += 1;
						error += deltax;
					}
				}
			}
			else
			{
				for (int x = x1; x > x2; x--)
				{
					drawArea->plotPixel(x, y, c);
					error = error - deltay;
					if (error < 0)
					{
						y -= 1;
						error -= deltax;
					}
				}
			}
		}
		/*else
		{
			float dX = deltay / deltax;

			if (deltay > 0)
			{
				for (int y = y1; y < y2; y++)
				{
					drawArea->plotPixel(int(x), y, c);
					x += dX;
				}
			}
			else
			{
				for (int y = y1; y > y2; y--)
				{
					drawArea->plotPixel(int(x), y, c);
					x -= dX;
				}
			}
		}*/
	}


	void DrawTask::drawCircle(int cx, int cy, int r, Colour c)
	{
		for (float y = 0; y <= r/sqrt(2); y++)
		{
			float x = sqrt(r * r - y * y);
			drawArea->plotPixel(int(cx + x), int(cy + y), c);
			drawArea->plotPixel(int(cx + x), int(cy - y), c);
			drawArea->plotPixel(int(cx - x), int(cy + y), c);
			drawArea->plotPixel(int(cx - x), int(cy - y), c);
			drawArea->plotPixel(int(cx + y), int(cy + x), c);
			drawArea->plotPixel(int(cx - y), int(cy + x), c);
			drawArea->plotPixel(int(cx + y), int(cy - x), c);
			drawArea->plotPixel(int(cx - y), int(cy - x), c);
		}
	}
	
	/*
	 * \param dt Change in time
	 *
	 * \note Make sure to clear the `drawArea` before you write to it.
	 */
	void DrawTask::update(float dt){
		drawArea->clear(Colour(0, 0, 0, 0));

		/*// Corners lines
		drawBresLine(0, 639, 512, 320, Colour(255, 255, 0, 255));
		drawBresLine(1023, 639, 512, 320, Colour(255, 255, 0, 255));
		drawBresLine(0, 0, 512, 320, Colour(255, 255, 0, 255));
		drawBresLine(1023, 0, 512, 320, Colour(255, 255, 0, 255));
		// Vertical lines
		drawBresLine(512, 639, 512, 320, Colour(0, 255, 0, 255));
		drawBresLine(512, 0, 512, 320, Colour(0, 255, 0, 255));
		// Horizontal lines
		drawBresLine(0, 320, 512, 320, Colour(0, 0, 255, 255));
		drawBresLine(1023, 320, 512, 320, Colour(0, 0, 255, 255));
		// Inbetween lines
		drawBresLine(0, 480, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(0, 160, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(256, 639, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(256, 0, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(1023, 480, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(1023, 160, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(768, 639, 512, 320, Colour(255, 0, 0, 255));
		drawBresLine(768, 0, 512, 320, Colour(255, 0, 0, 255));*/

		drawCircle(512, 320, 300, Colour(255, 255, 0, 255));

		// @BoundsCheck- requires using pushPixel
		// Plots pixels made to the drawArea this frame, clearing the pixel queue.
		// flushPixelQueue();
		app->getRenderer()->reloadTexture(drawArea);
	}


	/*
	 * Provides a bounds-checked and more efficient way to draw onto a surface then `plotPixel()`.
	 * Diagnostic messages for out-of-bounds drawing are displayed onto the console, and into `T3D_Log.txt`.
	 * 
	 * \param x x pixel coordinate to draw onto
	 * \param y y pixel coordinate to draw onto
	 * \param Colour pixel colour
	 *
	 */
	void DrawTask::pushPixel(int x, int y, Colour colour)
	{
		pixelPlotQueue.push_back(Pixel { x, y, colour }); 
	}

	/*
	 * Provides a bounds-checked and more efficient way to draw onto a surface then `plotPixel()`.
	 * Diagnostic messages for out-of-bounds drawing are displayed onto the console, and into `T3D_Log.txt`.
	 *
	 *
	 * \note This should be called at the end of the `update` function.
	 */
	void DrawTask::flushPixelQueue()
	{
		const uint32_t MaxOutOfBoundsCount = 10u;
		uint32_t OutOfBoundsCount = 0u;
		for (auto &Pixel : pixelPlotQueue)
		{
			bool PixelWithinWidth  = (Pixel.x >= 0 && Pixel.x < drawArea->getWidth());
			bool PixelWithinHeight = (Pixel.y >= 0 && Pixel.y < drawArea->getHeight());
			bool PixelWithinBounds = (PixelWithinWidth && PixelWithinHeight);

			if (PixelWithinBounds)
			{
				drawArea->plotPixel(Pixel.x, Pixel.y, Pixel.colour);
			}
			else 
			{
				if (OutOfBoundsCount < MaxOutOfBoundsCount)
				{
					logger::Log(priority::Tracing,
							    output_stream::File,
							    category::Debug,
							   "Pixel out of bounds!\n"
							   "\tWidth  :: [0 <= X <= %4u :: %4d :: %5s]%s\n"
							   "\tHeight :: [0 <= Y <= %4u :: %4d :: %5s]%s\n"
							   ,
							   app->getRenderer()->WindowWidth,
							   Pixel.x, PixelWithinWidth  ? "OK" : "ERROR",
							   PixelWithinWidth  ?   ""  : " <<<\n",
							   app->getRenderer()->WindowHeight,
							   Pixel.y, PixelWithinHeight ? "OK" : "ERROR",
							   PixelWithinHeight  ?  ""  : " <<<\n");
				}
				OutOfBoundsCount++;
			}
		}

		if (OutOfBoundsCount >= MaxOutOfBoundsCount)
		{
			logger::Log(priority::Tracing,
						output_stream::File,
						category::Debug,
					   "... Repeats %u times ...\n"
					   ,
					   OutOfBoundsCount - MaxOutOfBoundsCount);
		}

		pixelPlotQueue.clear();
	}



}
