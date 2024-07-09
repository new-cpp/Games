##  title: Games Related Conceptes

*FPS* : is the rate at which your system, and in particular, your GPU completes frames.
*HZ*  : cycles per second,the rate at which your display shows those completed frames.
        60 HZ is 60 times per second.


*Smoother Animations with High FPS* :
  For each "step" in the animation at 60FPS/Hz,there are 4 "steps" at 240FPS/Hz. These extra steps fill in the motion, making 240 FPS/Hz feel much smoother. At 240 FPS/Hz, there are 3 additional frames of information for your eyes to see in the same amount of time.

*Ghosting*
 is a distracting effect that happens on all LCD type displays. When the display refreshes, the colors do not change instantly. There is some time needed for the pixels to change, especially when the range of color change is large.

*Tearing* :
 is when the display is showing different frames from the GPU at the same time that causes a horizontal tear or image shift across the screen.
 Tearing occurs when the output rate of the GPU (FPS) does not match the display's Hz. In order to avoid tearing, we can turn on V-SYNC. V-SYNC effectively locks the output rate of the GPU to the Hz of the display. When V-SYNC is on, the GPU is only allowed to render one frame per display refresh cycle.

*System Latency*
 describes the time it takes your actions (mouse clicks, mouse movements, keyboard input) to reach your display. This is often called motion to photon, or click to muzzle flash latency.(Cpu + Gpu + Display time to render a frame)


*Homogeneous Coordinates* :
  - watch : https://www.youtube.com/watch?v=o-xwmTODTUI



