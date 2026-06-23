#include "banner.h"

static VOID EnableAnsiColor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }

    if (!GetConsoleMode(hOut, &dwMode)) {
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

static VOID CPrintLn(INT r, INT g, INT b, const CHAR* text) {
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m\n", r, g, b, text);
}

static VOID CPrint(INT r, INT g, INT b, const CHAR* text) {
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", r, g, b, text);
}

static VOID ShowRedBanner() {
    EnableAnsiColor();

    printf("\n");

    CPrintLn(255, 35, 35, "   _________..'..,                 __   ");
    CPrintLn(235, 10, 10, "  /   _____/_  _  __ ____   _____ _/  |_ ");
    CPrintLn(210, 0, 0, "  \\_____  \\\\ \\/ \\/ // __ \\_/ __ \\\\   __\\");
    CPrintLn(185, 0, 0, "  /   .'   \\\\  '  /\\  ___/\\  ___/ |  |  ");
    CPrintLn(155, 0, 0, " /____:__  / \\/\\_/  \\___  >\\___  >|__|  ");
    CPrintLn(110, 0, 0, "      ;  \\/..   ,    \\/     \\/       ");

    CPrintLn(145, 0, 0, "       .:'     .;      ,'.      `.       ");
    CPrintLn(125, 0, 0, "       ||  .   ||   '  ||   .    |       ");
    CPrintLn(105, 0, 0, "       ||      ::      ||        :       ");
    CPrintLn(85, 0, 0, "       :;      ..      ;:        .       ");
    CPrintLn(65, 0, 0, "        .              .                 ");

    printf("\n");

    CPrint(120, 0, 0, "               /\\_/\\");
    CPrintLn(180, 25, 25, "           SweetKatz");

    CPrint(165, 20, 20, "              (=^.^=)");
    CPrintLn(110, 0, 0, "  K A T Z");

    CPrint(90, 0, 0, "               >   <");
    CPrintLn(80, 0, 0, "           --------");

    printf("\n");

    CPrint(120, 0, 0, "        [ Author ] ");
    CPrintLn(180, 180, 180, "0xCubeX");

    CPrint(120, 0, 0, "        [ GitHub ] ");
    CPrintLn(180, 180, 180, "https://github.com/0xCubeX/SweetKatz");

    printf("\n");
}


static VOID ShowNormalBanner() {
    printf(
        "\n"
        "   _________                         __   \n"
        "  /   _____/_  _  __ ____   _____ _/  |_ \n"
        "  \\_____  \\\\ \\/ \\/ // __ \\_/ __ \\\\   __\\\n"
        "  /        \\\\     /\\  ___/\\  ___/ |  |  \n"
        " /_______  / \\/\\_/  \\___  >\\___  >|__|  \n"
        "         \\/             \\/     \\/       \n"
        "\n"
        "              /\\_/\\\         SweetKatz\n"
        "             ( o.o )  K A T Z\n"
        "              >   <         --------\n"
        "\n"
        "        [ Author ] 0xCubeX\n"
        "        [ GitHub ] https://github.com/0xCubeX/SweetKatz\n"
        "\n"
    );
}


VOID ShowBanner() {
    SYSTEMTIME st;

    GetLocalTime(&st);
    BOOLEAN IsNight = st.wHour >= 18 || st.wHour < 6;
    BOOLEAN RareDaytimeGlitch = (GetTickCount64() % 100) == 13;

    if (IsNight || RareDaytimeGlitch) {
        ShowRedBanner();
    }
    else {
        ShowNormalBanner();
    }
}