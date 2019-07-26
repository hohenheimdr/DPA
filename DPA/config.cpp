#include "config.h"


namespace config
{
   method_conf ExG = {DPA_Image::ExG};
   method_conf ExR = {DPA_Image::ExR};
   method_conf ExGR = {DPA_Image::ExGR};

   filter_conf Filter;
   editing_conf ImgEditing;
}

bool config::load_config_file()
{
    // Code to load and set the configuration variables
}
