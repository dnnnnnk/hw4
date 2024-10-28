#include <iostream>
#include <vector>
#include <format>

class Sales {
    const int Sellers;
    const int Goods;
    std::vector<std::vector<int>> salesTable;
    std::vector<std::vector<double>> pricesTable;
    std::vector<std::vector<double>> multipliedSP;
public:
    explicit Sales(const int& Sellers = 0, const int& Goods = 0) :
    Sellers(Sellers), Goods(Goods),
    salesTable(Sellers, std::vector<int>(Goods, 0)),
    pricesTable(Goods, std::vector<double>(2, 0)),
    multipliedSP(Sellers, std::vector<double>(2, 0))
    {
        if (Sellers == 0 || Goods == 0) {
            throw std::invalid_argument("\nколичество продавцов/товаров не может быть равно 0");
        }
    }
    ~Sales() {
        std::cout << "до новых встреч!" << std::endl;
    }

    void setDefaultSalesTable() {
        salesTable = {
            {5, 2, 0, 10},
            {3, 5, 2, 5},
            {20, 0, 0, 0}
        };
    }

    void setDefaultPricesTable() {
        pricesTable = {
            {1.20, 0.50},
            {2.80, 0.40},
            {5.00, 1.00},
            {2.00, 1.50}
        };

    }

    void setSalesTable() {
        for (int i = 0; i < Sellers; i++) {
            for (int j = 0; j < Goods; j++) {
                std::cout << std::format("сколько {}-го товара продал {}-й продавец? ", j+1, i+1);
                std::cin >> salesTable[i][j];
            }
            std::cout << std::endl;
        }
    }

    void setPricesTable() {
        for (int i = 0; i < Goods; i++) {
            std::cout << std::format("цена {}-ого товара: ", i+1);
            std::cin >> pricesTable[i][0];
            std::cout << std::format("комиссионные {}-ого товара: ", i+1);
            std::cin >> pricesTable[i][1];
            std::cout << std::endl;
        }
    }

    void checkSalesTable() const {
        for (int i = 0; i < Sellers; i++) {
            for (int j = 0; j < Goods; j++) {
                std::cout << salesTable[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void checkPricesTable() const {
        for (int i = 0; i < Goods; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << pricesTable[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::array<double, 4> multipleSP() {
        double min = std::numeric_limits<double>::max();
        double max = 0;
        double topSeller = 0;
        double brokeSeller = 0;
        double totalSalesMoney = 0;
        double totalCommissionMoney = 0;

        for (int i = 0; i < Sellers; i++) {
            double salesMoney = 0;
            double commissionMoney = 0;
            for (int j = 0; j < Goods; j++) {
                salesMoney += salesTable[i][j]*pricesTable[j][0];
                commissionMoney += salesTable[i][j]*pricesTable[j][1];
            }
            multipliedSP[i][0] = salesMoney;
            multipliedSP[i][1] = commissionMoney;

            if (salesMoney < min) {
                min = salesMoney;
                brokeSeller = i+1;
            }
            if (salesMoney > max) {
                max = salesMoney;
                topSeller = i+1;
            }
            totalSalesMoney += salesMoney;
            totalCommissionMoney += commissionMoney;
        }
        const std::array result = {brokeSeller, topSeller, totalSalesMoney, totalCommissionMoney};
        return result;
    }

};

void firstMethod(Sales& sales);
void secondMethod(Sales& sales);
void getMenu();
void printResultLines(std::array<double, 4>& result);

void eighthTask() {
    int method = 0;

    std::cout << "1 - заранее заданные значения\n"
                 "2 - самостоятельный ввод значений\n"
                 "каким методом пойдем? "; std::cin >> method;
    std::cout << std::endl;
    int Sellers = 3;
    int Goods = 4;
    if (method == 2) {
        std::cout << "введите кол-во продавцов: "; std::cin >> Sellers;
        std::cout << "введите кол-во товаров: "; std::cin >> Goods;
        std::cout << std::endl;
    }
    Sales sales(Sellers, Goods);
    switch (method) {
        case 1:
            firstMethod(sales);
        break;
        case 2:
            secondMethod(sales);
        break;
        default:
            std::cout << "неправильный метод!" << std::endl;
        break;
    }
}

void firstMethod(Sales& sales) {
    sales.setDefaultSalesTable();
    sales.setDefaultPricesTable();
    std::array<double, 4> result = sales.multipleSP();

    printResultLines(result);

}

void secondMethod(Sales& sales) {
    bool isNull = false;
    std::array<double, 4> result{};

    getMenu();

    while (!isNull) {
        int action; std::cin >> action;
        switch (action) {
            case 0:
                isNull = true;
            break;
            case 1:
                sales.setSalesTable();
            break;
            case 2:
                sales.setPricesTable();
            break;
            case 3:
                sales.checkSalesTable();
            break;
            case 4:
                sales.checkPricesTable();
            break;
            case 5:
            result = sales.multipleSP();
            printResultLines(result);
            break;
            case 6:
                getMenu();
            break;
            default:
                std::cout << "неправильное действие!" << std::endl;
            break;
        }
    }

}

void getMenu() {
    std::cout <<     "0) ВЫХОД\n"
                     "1) задать таблицу продавец/товар \n"
                     "2) задать таблицу товар (цена, комиссионные) \n"
                     "3) проверить таблицу продавец/товар\n"
                     "4) проверить таблицу товар (цена, комиссионные) \n"
                     "5) умножить таблицы и получить результат \n"
                     "6) вывод меню\n";
    std::cout << std::endl;
}

void printResultLines(std::array<double, 4>& result) {
    std::cout << std::format("минимально выручил денег:     {}-й продавец \n"
                                   "максимально выручил денег:    {}-й продавец \n"
                                   "общая выручка:                {:.2f} \n"
                                   "общие комиссионные:           {:.2f} \n"
                                   "общая сумма денег:            {:.2f} \n",
        result[0], result[1], result[2], result[3], result[2]+result[3]) << std::endl;
}

