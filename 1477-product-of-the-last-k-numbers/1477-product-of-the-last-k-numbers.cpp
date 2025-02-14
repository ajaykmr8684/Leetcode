class ProductOfNumbers {
private:
    vector<int> multprefix;
public:
    ProductOfNumbers() {
        multprefix.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            multprefix.clear();
            multprefix.push_back(1);
        } else {
            multprefix.push_back(multprefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = multprefix.size();
        if (k >= n) return 0;
        return multprefix[n - 1] / multprefix[n - k - 1];
    }
};