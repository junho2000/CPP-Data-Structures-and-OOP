Point &operator-(Point &ref)
        {
               xpos = -ref.xpos;
               ypos = -ref.ypos;
               return *this;
        }