int solution(int price) {
    if (price < 100000)
        return price;
    else if (price < 300000)
        return price *= 0.95;
    else if (price < 500000)
        return price *= 0.9;
    else {
        return price *= 0.8;
    }
}