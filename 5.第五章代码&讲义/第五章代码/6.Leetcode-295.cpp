class MedianFinder {
public:
    typedef pair<int, int> PII;
    int tot;
    set<PII> s1, s2;
    MedianFinder() {
        tot = 0;
    }
    
    void addNum(int num) {
        if (s1.size() == 0 || num < -s1.begin()->first) {
            s1.insert(PII(-num, tot++));
        } else {
            s2.insert(PII(num, tot++));
        }
        int n1 = (s1.size() + s2.size() + 1) / 2;
        if (n1 == s1.size()) return ;
        if (s1.size() < n1) {
            s1.insert(PII(-s2.begin()->first, tot++));
            s2.erase(s2.begin());
        } else {
            s2.insert(PII(-s1.begin()->first, tot++));
            s1.erase(s1.begin());
        }
        return ;
    }
    
    double findMedian() {
        if ((s1.size() + s2.size()) % 2) {
            return -s1.begin()->first;
        }
        double a = -s1.begin()->first;
        double b = s2.begin()->first;
        return (a + b) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
