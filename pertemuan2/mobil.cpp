#define NOMINMAX
#include <windows.h>
#include <graphics.h>

int main() {
    initwindow(1000, 600, "Landscape Animation");

    // ================= BACKGROUND =================
    setcolor(LIGHTCYAN);
    rectangle(0, 0, 1000, 600);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(1, 1, LIGHTCYAN);

    // Matahari
    setcolor(YELLOW);
    circle(650, 100, 75);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(651, 101, YELLOW);

    // Awan
    setcolor(WHITE);
    circle(700, 70, 30); floodfill(701, 71, WHITE);
    circle(750, 65, 40); floodfill(755, 67, WHITE);
    circle(800, 55, 20); floodfill(805, 56, WHITE);

    // ================= ANIMASI =================
    for (int i = 0; i < 1000; i++) {

        // Jalan
        setfillstyle(SOLID_FILL, BLACK);
        bar(0, 442, 1000, 600);

        // Garis jalan
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        for(int j = 0; j < 1000; j += 120) {
            bar(j, 503, j + 80, 508);
        }

        // Pohon
        setfillstyle(SOLID_FILL, BROWN);
        bar(300, 350, 310, 460);
        setcolor(GREEN);
        circle(305, 350, 40);
        floodfill(306, 351, GREEN);

        // ================= TRUK =================
        // Body
        setcolor(RED);
        rectangle(16 + i, 442, 296 + i, 540);
        setfillstyle(SOLID_FILL, RED);
        floodfill(17 + i, 443, RED);

        // Kepala
        setcolor(LIGHTGRAY);
        rectangle(299 + i, 464, 374 + i, 544);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        floodfill(300 + i, 465, LIGHTGRAY);

        // Kaca
        setcolor(WHITE);
        rectangle(315 + i, 474, 374 + i, 506);
        floodfill(316 + i, 475, WHITE);

        // Ban luar
        setcolor(WHITE);
        circle(72 + i, 544, 20); floodfill(72 + i, 545, WHITE);
        circle(124 + i, 544, 20); floodfill(125 + i, 545, WHITE);
        circle(327 + i, 544, 20); floodfill(328 + i, 545, WHITE);

        // Ban dalam
        setcolor(BLACK);
        circle(72 + i, 544, 10); floodfill(72 + i, 545, BLACK);
        circle(124 + i, 544, 10); floodfill(125 + i, 545, BLACK);
        circle(327 + i, 544, 10); floodfill(328 + i, 545, BLACK);

        delay(5);

        // Hapus truk sebelumnya (biar ga numpuk)
        setfillstyle(SOLID_FILL, BLACK);
        bar(0, 442, 1000, 600);
    }

    getch();
    closegraph();
    return 0;
}
