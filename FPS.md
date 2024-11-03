
source : https://qualified.one/blog/game_dev/six-methods-of-fps-calculation/

# 6 methods to calcule fps:
  ## fixed interval method: 
    FPS = FRAME-NB / elapsed-time

    int fps()
    {
        static int fps = 0;
        static last_time = get_time(); // ms
        static frame_count = 0;

        ++frame_count;
        int curr_time = get_time();
        if(curr_time - last_time > 1000)
        {
            last_time = curr_time;
            fps = frame_count;
            frame_count = 0;

        }

        return fps;
    }

    - same but diffenret writing 

    int fps(int delta_time)
    {
       static int fps = 0;
       static time_left = 1000;
       static frame_count = 0;

       time_left -= delta_time;
       if(time_left < 0)
       {
            fps = frame_count;
            frame_count = 0;
            time_left = 1000;
       }
       return fps
    }

   ## fixed frame time methods:
   
   int fps()
   {
        static int fps = 0;
        static last_time = get_time();//ms
        static count_frame = 0;
        
        if(count_frame >=100)
        {
            int curr_time = get_time();
            fps = count_frame / (curr_time - last_time)*1000;
            last_time = curr_time;
            count_frame = 0;
        }
        return fps;
   }


   ## real time fps calcule:
   int fps(int delta_time)
   {
        int fps = (1.f / delta_time * 1000); // 1 frame per delta_time
        reutn fps;
   }


   ## common average method:
   int begin_time = get_time();

   int fps()
   {
        static frame_count = 0;
        ++frame_count;

        int fps = (frame_count / (get_time() - begin_time)*1000;

        return fps;
   }

   ## exact sampling method:
   
    - sample the first N frame and than calculate the average.

    int fps(int delta_time)
    {
       static queue<int> q;
       static sum_duration = 0;
       static fps = 0;
       if(q.size() < 100)
       {
         sum_duration += delta_time;
         q.push(delta_time);

         fps = (q.size())/ (sum_duration * 1000);
       }
       else
       {
        sum_duration -=q.front();
        sum_duration += delta_time();

        q.pop();
        q.push(delta_time);

        fps = (100 / (sum_duration * 1000);
       }
    }


    ## average sampling method

    int fps(int delta_time)
    {
        float avg_duration = 0;
        float alph = (1.f / 100.f) ; // 100 samples;

        int frame_count = 0;

        ++frame_count;
        if(1 == frame_count)
        {
            avg_duration = delta_time;
        }
        else
        {
            avg_duration= avg_duration * (1 - alpha) + delta_time * alpha;
        }

        return  1/ avg_duration;

    }
