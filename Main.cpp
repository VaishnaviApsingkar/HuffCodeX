
#include "PartOne.h"
#include "PartTwo.h"
#include "PartThreeA.h"
#include "PartThreeB.h"
#include "PartFourA.h"
#include "PartFourB.h"

// Main function that runs each part of code sequentially.

int main() {

    // Providing the file names that each part requires as a parameter.
    runPartOne("clear.txt", "freq.txt");
    runPartTwo("freq.txt", "codetable.txt");
    runPartThreeA("clear.txt", "codetable.txt", "coded.txt");
    runPartThreeB("codetable.txt", "coded.txt", "clear.txt", "decoded.txt");
    runPartFourA("clear.txt", "codetable.txt", "codedalt.txt");
    runPartFourB("codedalt.txt", "codetable.txt", "decodedalt.txt");
    return 0;
}