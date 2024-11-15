#include "stdafx.h"

int main()
{
    FRAMEWORK.Init(640, 480, "SFML Framework");
    FRAMEWORK.Do();
    FRAMEWORK.Release();
    return 0;
}
