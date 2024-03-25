#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void PrintBlock(ForeColour colour) {
    std::cout << "\033[" << colour << "m";
    std::cout << "■";
    std::cout << "\033[" << Default << "m";
}

int main() {
    int num;
    std::cout << "\x1b[033m" << "아름다운 색!! 우왕" << std::endl;
    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번 : 202027067" << std::endl;
    std::cout << "이름 : 배현준" << std::endl << std::endl;
    while (1) {
        std::cout << "화면에 그릴 물체코드를 입력하세요 : ";
        std::cin >> num;

        ForeColour colour = Default;
        switch (num) {
        case 1:
            colour = White;
            break;
        case 2:
            colour = Red;
            break;
        case 4:
            colour = Green;
            break;
        case 8:
            colour = Yellow;
            break;
        case 16:
            colour = Cyan;
            break;
        case 32:
            colour = Magenta;
            break;
        case 64:
            std::cout << "프로그램 종료" << std::endl;
            return 0;
        default:
            std::cout << "잘못된 코드입니다." << std::endl;
            continue;
        }

        PrintBlock(colour);
        std::cout << std::endl;
    }

    return 0;

    /*
    * 흰색 블록을 그리는 키코드 : 1 (1)
    * 빨강색 블록을 그리는 키코드 : 2 (10)
    * 녹색 블록을 그리는 키코드 : 4 (100)
    * 노란색 블록을 그리는 키코드 : 8 (1000)
    * 청록색 블록을 그리는 키코드 : 16 (10000)
    * 마젠타색 블록을 그리는 키코드 : 32 (100000)
    * 프로그램 종료 : 64 (1000000)
    *
    * 프로그램을 시작하면 아래와 같이 쓰시오
    *
    *
    * 화면에 그림을 그리는 프로그램입니다.
    * 학번 : 349218347(본인학번)
    * 이름 : 본인이름
    *
    * 화면에 그릴 물체코드를 입력하세요 :
    * (반복)
    */
}
