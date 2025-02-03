// ! Order Foods simulation of indonesian local restaurant.
// ! This is a simple console application in CLI.
// ? Using Modular technique
// ? Made by Love Beginner Dev., Alexander Kart van Stein.
// * program code in below, open source for learning ^-^
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    int price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
    int totalPrice;
} Order;

void displayMainMenu() {
    printf("======= Restoran BurkenBerg Food =======\n");
    printf("Note: Anda bisa menghapus order setelah memilihnya.\n");
    printf(" 1. Makanan\n");
    printf(" 2. Minuman\n");
    printf(" 3. Camilan\n");
    printf(" 4. Lihat pesanan? dan Checkout!\n");
    printf("=================================\n");
    printf("Masukkan pilihan Anda (1-4): ");
}

void displayFoodMenu() {
    printf("===== Makanan =====\n");
    printf(" 1. Nasi Goreng Ayam - Rp 20,000\n");
    printf(" 2. Nasi Goreng Sapi - Rp 25,000\n");
    printf(" 3. Mie Goreng Ayam - Rp 18,000\n");
    printf(" 4. Mie Goreng Sapi - Rp 22,000\n");
    printf("=================================\n");
    printf("Pilih makanan Anda (1-4): ");
}

void displayDrinkVariantsMenu() {
    printf("===== Variasi Minuman =====\n");
    printf(" 1. Hangat\n");
    printf(" 2. Dingin\n");
    printf("=================================\n");
    printf("Pilih varian minuman Anda (1-2): ");
}

void displayWarmDrinkMenu() {
    printf("===== Minuman Hangat =====\n");
    printf(" 1. Teh Hangat - Rp 5,000\n");
    printf(" 2. Kopi - Rp 10,000\n");
    printf(" 3. Susu - Rp 8,000\n");
    printf("=================================\n");
    printf("Pilih minuman hangat Anda (1-3): ");
}

void displayColdDrinkMenu() {
    printf("===== Minuman Dingin =====\n");
    printf(" 1. Es Teh - Rp 6,000\n");
    printf(" 2. Es Kopi - Rp 12,000\n");
    printf(" 3. Es Cokelat - Rp 10,000\n");
    printf("=================================\n");
    printf("Pilih minuman dingin Anda (1-3): ");
}

void displayDessertMenu() {
    printf("===== Camilan =====\n");
    printf(" 1. Fried Meals  - Variant\n");
    printf(" 2. Seblakkkk    - Variant\n");
    printf(" 3. ice cream    - Variant\n");
    printf(" 4. Puding       - Variant\n");
    printf("=================================\n");
    printf("Pilih camilan Anda (1-4): ");
}

void displaySubDessert_FriedFoods() {
    printf("===== Gorengan =====\n");
    printf(" 1. Pempek palembang - Rp 12,000\n");
    printf(" 2. Kentang Goreng - Rp 8,000\n");
    printf(" 3. Cireng Ayam Pedas Jumbo! - Rp 6,000\n");
    printf("=================================\n");
    printf("Pilih gorengan Anda (1-3): ");
}

void displaySubDessert_SeblakFoods() {
    printf("===== Seblak Menu's =====\n");
    printf(" 1. Seblak ceker - Rp 8,000\n");
    printf(" 2. Seblak Rafael - Rp 6,000\n");
    printf(" 3. Seblak tetelan iblis - Rp 10,000\n");
    printf("=================================\n");
    printf("Pilih seblakkkk Anda (1-3): ");
}

void displaySubDessert_IceCreams() {
    printf("===== Ice Creams! =====\n");
    printf(" 1. Vanilla - Rp 4,000\n");
    printf(" 2. Strawberry - Rp 4,500\n");
    printf(" 3. Chocolate - Rp 4,000\n");
    printf(" 4. Matcha - Rp 4,500\n");
    printf(" 5. Durian - Rp 4,500\n");
    printf("=================================\n");
    printf("Pilih ice cream Anda (1-5): ");
}

void displaySubDessert_Puddings() {
    printf("===== Pudding's =====\n");
    printf(" 1. Mango       - Rp 5,000\n");
    printf(" 2. Peach       - Rp 5,000\n");
    printf(" 3. Chocolate   - Rp 5,000\n");
    printf(" 4. Coconut     - Rp 5,000\n");
    printf("=================================\n");
    printf("Pilih puding Anda (1-4): ");
}

void addToOrder(Order *order, const char *name, int price) {
    if (order->count < MAX_ITEMS) {
        snprintf(order->items[order->count].name, 50, "%s", name);
        order->items[order->count].price = price;
        order->count++;
        order->totalPrice += price;
        printf("Ditambahkan ke pesanan: %s - Rp %d\n", name, price);
    } else {
        printf("Pesanan penuh, tidak bisa menambahkan item lagi.\n");
        printf("[ INFO : Sudah mencapai batas maksimal Item 10/10 ]");
    }
}

void removeFromOrder(Order *order) {
    if (order->count == 0) {
        printf("Pesanan Anda kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    int index;
    printf("\nPilih nomor item yang ingin dihapus (1-%d): ", order->count);
    scanf("%d", &index);

    if (index < 1 || index > order->count) {
        printf("Nomor item tidak valid.\n");
        return;
    }

    index--; // Sesuaikan ke indeks array
    order->totalPrice -= order->items[index].price;

    for (int i = index; i < order->count - 1; i++) {
        order->items[i] = order->items[i + 1];
    }

    order->count--;
    printf("Item berhasil dihapus.\n");
}

void displayOrderSummary(Order *order) {
    printf("\n===== Ringkasan Pesanan =====\n");
    if (order->count == 0) {
        printf("Pesanan Anda kosong.\n");
    } else {
        for (int i = 0; i < order->count; i++) {
            printf("%d. %s - Rp %d\n", i + 1, order->items[i].name, order->items[i].price);
        }
        printf("=================================\n");
        printf("Total Harga: Rp %d\n", order->totalPrice);
    }
}

void checkout(Order *order) {
    if (order->count == 0) {
        printf("Pesanan Anda kosong, tidak ada yang perlu dibayar.\n");
        return;
    }

    int bayar;
    printf("\n~ ~ ~ ~ Pembayaran ~ ~ ~ ~\n");
    printf("\nMasukkan jumlah uang Anda: Rp ");
    scanf("%d", &bayar);

    if (bayar >= order->totalPrice) {
        printf("=================================\n");
        printf("[ Pembayaran berhasil! ]\n Kembalian Anda: Rp %d,-\n", bayar - order->totalPrice);
        printf("Terima kasih telah melakukan pembayaran!\n");
        // Reset pesanan
        order->count = 0;
        order->totalPrice = 0;
    } else {
        printf("=================================\n");
        printf("[ Pembayaran Gagal! ].\n Pastikan saldo anda mencukupi jumlah transaksi.\n");
        printf("Total Nominal yang Seharusnya dibayar: Rp %d\n", order->totalPrice);
    }

    printf("\nTekan Enter untuk kembali ke menu utama...\n");
    getchar(); // Tunggu user menekan Enter
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Order order = {.count = 0, .totalPrice = 0};
    int mainMenuChoice, variantChoice, subMenuChoice, subDesertMenu;

    while (1) {
        system("cls"); // Bersihin layar (gunakan "clear" pada CLI)
        displayMainMenu();
        scanf("%d", &mainMenuChoice);

        switch (mainMenuChoice) {
            case 1: // menu hidangan makanan
                system("cls");
                displayFoodMenu();
                scanf("%d", &subMenuChoice);
                switch (subMenuChoice) {
                    case 1: addToOrder(&order, "Nasi Goreng Ayam", 20000); break;
                    case 2: addToOrder(&order, "Nasi Goreng Sapi", 25000); break;
                    case 3: addToOrder(&order, "Mie Goreng Ayam", 18000); break;
                    case 4: addToOrder(&order, "Mie Goreng Sapi", 22000); break;
                    default: printf("Pilihan tidak valid.\n"); break;
                }
                break;
            case 2: // menu minuman
                system("cls");
                displayDrinkVariantsMenu();
                scanf("%d", &variantChoice);

                switch (variantChoice) {
                    case 1: // Hangat
                        system("cls");
                        displayWarmDrinkMenu();
                        scanf("%d", &subMenuChoice);
                        switch (subMenuChoice) {
                            case 1: addToOrder(&order, "Teh Hangat", 5000); break;
                            case 2: addToOrder(&order, "Kopi", 10000); break;
                            case 3: addToOrder(&order, "Susu", 8000); break;
                            default: printf("Pilihan tidak valid.\n"); break;
                        }
                        break;

                    case 2: // Dingin
                        system("cls");
                        displayColdDrinkMenu();
                        scanf("%d", &subMenuChoice);
                        switch (subMenuChoice) {
                            case 1: addToOrder(&order, "Es Teh", 6000); break;
                            case 2: addToOrder(&order, "Es Kopi", 12000); break;
                            case 3: addToOrder(&order, "Es Cokelat", 10000); break;
                            default: printf("Pilihan tidak valid.\n"); break;
                        }
                        break;

                    default:
                        printf("Pilihan tidak valid.\n");
                        break;
                }
                break;
            case 3: // menu camilan
                // printf("Menu camilan belum tersedia. Coming Soon\n");
                system("cls");
                displayDessertMenu();
                scanf("%d", &subDesertMenu);

                switch(subDesertMenu) {
                    case 1:
                    system("cls");
                    displaySubDessert_FriedFoods();
                    scanf("%d", &subMenuChoice);
                    switch (subMenuChoice) {
                            case 1: addToOrder(&order, "Pempek Palembang", 12000); break;
                            case 2: addToOrder(&order, "Kentang Goreng", 8000); break;
                            case 3: addToOrder(&order, "Cireng Ayam Pedas Jumbo", 6000); break;
                            default: printf("Pilihan tidak valid.\n"); break;
                        }
                    break;

                    case 2:
                    system("cls");
                    displaySubDessert_SeblakFoods();
                    scanf("%d", &subMenuChoice);
                    switch (subMenuChoice) {
                            case 1: addToOrder(&order, "Seblak Ceker", 8000); break;
                            case 2: addToOrder(&order, "Seblak Rafael", 6000); break;
                            case 3: addToOrder(&order, "Seblak Tetelan Iblis", 10000); break;
                            default: printf("Pilihan tidak valid.\n"); break;
                        }
                    break;

                    case 3:
                    system("cls");
                    displaySubDessert_IceCreams();
                    scanf("%d", &subMenuChoice);
                    switch (subMenuChoice) {
                            case 1: addToOrder(&order, "Ice Cream Vanilla", 4000); break;
                            case 2: addToOrder(&order, "Ice Cream StrawBerry", 4500); break;
                            case 3: addToOrder(&order, "Ice Cream Chocolate", 4000); break;
                            case 4: addToOrder(&order, "Ice Cream Matcha", 4500); break;
                            case 5: addToOrder(&order, "Ice Cream Durian", 4500); break;
                            default: printf("Pilihan tidak valid.\n"); break;
                        }
                    break;

                    case 4:
                    system("cls");
                    displaySubDessert_Puddings();
                    scanf("%d", &subMenuChoice);
                    switch (subMenuChoice) {
                            case 1: addToOrder(&order, "Manggo Pudding", 5000); break;
                            case 2: addToOrder(&order, "Peach Pudding", 5000); break;
                            case 3: addToOrder(&order, "Chocolate Pudding", 5000); break;
                            case 4: addToOrder(&order, "Coconut Pudding", 5000); break;
                            default: printf("Pilihan tidak valid.\n"); break;
                        }
                    break;
                }
                break;
            case 4: //Lihat pesanan dan checkout item
                system("cls");
                displayOrderSummary(&order);

                if (order.count == 0) {
                    printf("\nPesanan kosong. Tekan Enter untuk kembali ke menu utama...\n");
                    getchar();
                } else {
                    printf("\n1. Hapus Item\n");
                    printf("2. Konfirmasi dan Bayar\n");
                    printf("3. Kembali ke LihatMenu Utama (Tekan Enter kembali)\n");
                    printf("Pilih opsi Anda: ");
                    int action;
                    scanf("%d", &action);
                    clearInputBuffer();

                    switch (action) {
                        case 1:
                            removeFromOrder(&order);
                            break;
                        case 2:
                            checkout(&order);
                            break;
                        case 3:
                            // Langsung keluar dari switch dan kembali ke menu utama
                            break;
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    }
                }
                break;

            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
        if (mainMenuChoice != 4) {
            printf("\nTekan Enter untuk kembali ke menu utama...\n");
            getchar();
        }

        // printf("\nTekan Enter untuk kembali ke menu utama...\n");
        getchar(); // Tunggu input sebelum kembali ke menu
    }
}
