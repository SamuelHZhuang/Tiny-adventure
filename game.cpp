#include <iostream>
#include <string>
#include <vector>
using namespace std;

int health = 100;
bool hasCrystal = false;
bool hasRuneBlade = false;

void status() {
    cout << "\n--- STATUS ---\n";
    cout << "Health: " << health << endl;
    cout << "Inventory: ";
    if (!hasCrystal && !hasRuneBlade) cout << "Empty";
    if (hasCrystal) cout << "Aether Crystal ";
    if (hasRuneBlade) cout << "Rune Blade ";
    cout << "\n--------------\n";
}

void forest() {
    cout << "\nYou enter the Whispering Forest. The trees hum with ancient magic.\n";
    cout << "1. Follow the glowing path\n";
    cout << "2. Investigate a ruined shrine\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "\nA shadow beast attacks you from the mist!\n";
        if (hasRuneBlade) {
            cout << "You slay it easily with the Rune Blade.\n";
        } else {
            cout << "You barely escape, wounded.\n";
            health -= 25;
        }
    } else {
        cout << "\nInside the shrine, you find a glowing Aether Crystal.\n";
        hasCrystal = true;
    }
}

void mountain() {
    cout << "\nYou climb the Obsidian Peaks, where dragons once ruled.\n";
    cout << "A stone guardian blocks your path.\n";

    if (hasCrystal) {
        cout << "The Aether Crystal resonates and calms the guardian.\n";
        cout << "Behind it, you find the legendary Rune Blade!\n";
        hasRuneBlade = true;
    } else {
        cout << "The guardian strikes you with crushing force.\n";
        health -= 30;
    }
}

void finalBattle() {
    cout << "\nYou reach the Aether Nexus, where the Void Sorcerer awaits.\n";

    if (hasRuneBlade && hasCrystal) {
        cout << "With crystal and blade combined, Bammy unleashes pure magic.\n";
        cout << "The Void Sorcerer is defeated!\n";
        cout << "\n🌟 YOU WIN 🌟\n";
    } else {
        cout << "You fight bravely, but lack the power to win.\n";
        cout << "\n💀 BAMMY FALLS, BUT BECOMES A LEGEND 💀\n";
    }
}

int main() {
    cout << "=== THE LEGEND OF BAMMY AND THE SHATTERED AETHER ===\n";
    cout << "Bammy, a young wanderer, seeks to restore magic to the realm.\n";

    while (health > 0) {
        status();
        cout << "\nWhere will Bammy go?\n";
        cout << "1. Whispering Forest\n";
        cout << "2. Obsidian Mountains\n";
        cout << "3. Face the Void Sorcerer\n";

        int choice;
        cin >> choice;

        if (choice == 1) forest();
        else if (choice == 2) mountain();
        else if (choice == 3) {
            finalBattle();
            break;
        } else {
            cout << "Invalid choice.\n";
        }

        if (health <= 0) {
            cout << "\nBammy collapses from their wounds.\n";
            cout << "GAME OVER \n";
        }
    }

    return 0;
}

