#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include "dpa_image.h"

namespace config    //evtl. zu Klasse ändern und das Objekt beim Aufrufen der Funktionen weitergeben.
{
    struct method_conf
    {
        const DPA_Image::kindOfMethod Method;
        DPA_Image::kindOfThresh Threshold;
        int Threshold_Value;
    };
    struct filter_conf
    {
        DPA_Image::filter_settings FilterSettings;
        DPA_Image::kindOfColorSpace ColorSpace;
        DPA_Image::colorChangeType ColorChangeType;
        float min1, max1, min2, max2, min3, max3;
    };

    struct cropping
    {
        int x, y, width, height;
    };

    struct rotation
    {
         int angle;
    };

    struct editing_conf
    {
        bool edited;
        cropping crop;
        rotation rotate;
    };

    extern method_conf  ExG, ExR, ExGR;
    extern filter_conf Filter;
    extern editing_conf ImgEditing;

    bool load_config_file();
}

#endif // CONFIG_H
