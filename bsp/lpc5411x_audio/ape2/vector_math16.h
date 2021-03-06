/*

libdemac - A Monkey's Audio decoder

Copyright (C) Dave Chapman 2007

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA

*/
//justin added
#define inline __inline


static inline void vector_add(int16_t* v1, int16_t* v2)
{
#if ORDER > 32
    int order = (ORDER >> 5);
    while (order--)
#endif
    {
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
#if ORDER > 16
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
        *v1++ += *v2++;
#endif
    }
}

static inline void vector_sub(int16_t* v1, int16_t* v2)
{
#if ORDER > 32
    int order = (ORDER >> 5);
    while (order--)
#endif
    {
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
#if ORDER > 16
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
        *v1++ -= *v2++;
#endif
    }
}

static inline int32_t scalarproduct(int16_t* v1, int16_t* v2)
{
    int res = 0;

#if ORDER > 16
    int order = (ORDER >> 4);
    while (order--)
#endif
    {
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
        res += *v1++ * *v2++;
    }
    return res;
}
