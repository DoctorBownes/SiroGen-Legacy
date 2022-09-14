#ifndef COLOR_H_
#define COLOR_H_
#include <vector>
#include <cstdint>

class Color
{
public:
	Color();
	Color(uint8_t r, uint8_t g, uint8_t b);
	~Color();

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
};

#define BKG	0
#define BLK 1
#define NVY 2
#define BLU 3
#define MRN 4
#define PUR 5
#define VLT 6
#define RED 7
#define ROS 8
#define MGA 9
#define FOR 10
#define TEA 11
#define AZR 12
#define OLV 13
#define GRY 14
#define ICE 15
#define ORG 16
#define PCH 17
#define PNK 18
#define GRN 19
#define JAD 20
#define CYN 21
#define LIM 22
#define MIN 23
#define CLS 24
#define YLW 25
#define CRM 26
#define WHT 27


class Palette
{
public:
    Palette(const Palette&) = delete;

    static Palette* GetInstance()
    {
        if (!_palette)
        {
            _palette = new Palette();
        }
        return _palette;
    }

    //Based on ZX Spectrum color palette.
    const Color Colors[28] =
    {
        Color(0,0,0)        ,
        Color(0,0,0)        ,
        Color(0,0,128)      ,
        Color(0,0,255)      ,
        Color(128,0,0)      ,
        Color(128,0,128)    ,
        Color(128,0,255)    ,
        Color(255,0,0)      ,
        Color(255,0,128)    ,
        Color(255,0,255)    ,
        Color(0,128,0)      ,
        Color(0,128,128)    ,
        Color(0,128,255)    ,
        Color(128,128,0)    ,
        Color(128,128,128)  ,
        Color(128,128,255)  ,
        Color(255,128,0)    ,
        Color(255,128,128)  ,
        Color(255,128,255)  ,
        Color(0,255,0)      ,
        Color(0,255,128)    ,
        Color(0,255,255)    ,
        Color(128,255,0)    ,
        Color(128,255,128)  ,
        Color(128,255,255)  ,
        Color(255,255,0)    ,
        Color(255,255,128)  ,
        Color(255,255,255)  ,
    };

private:
    Palette();
    ~Palette();
    static Palette* _palette;
};

#endif
