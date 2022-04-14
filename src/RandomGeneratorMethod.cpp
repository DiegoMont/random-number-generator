namespace RandomGeneratorMethod {
    int midSquare(int x0) {
        int square = x0 * x0;
        int withoutRightDigits = square / 100;
        return withoutRightDigits % 10000;
    }
}
