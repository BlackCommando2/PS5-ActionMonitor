class Listner{
    public:
    bool *btnStatus;
    Listner(bool *btn)
    {
        this->btnStatus=btn;
    }
    bool check()
    {
        return *btnStatus;
    }
};