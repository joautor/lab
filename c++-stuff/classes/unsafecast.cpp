#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Ah {
public:
    Ah() {}
    virtual void moan()
    {
        LOG("Ahh ahh ahh");
    }
};

class Oh: public Ah {
public:
    Oh() {
        mydata = 143;
    }
    void moan() override
    {
        LOG("ahhh ohhh ohh");
    }

    void onlyme() {
        LOG("only me");
        LOG(mydata);
    }
private:
    int mydata;
};

class Yes: public Ah {
public:
    Yes() {}
    void moan() override
    {
        LOG("Ahh yes yes yes");
    }
};

void command(Ah* ah)
{
    if (ah == nullptr) {
        LOG("ah is null pointer");
        return;
    }
    Oh* oh = (Oh*)ah;
    // Oh* oh = static_cast<Oh*>(ah);
    oh->moan();
    oh->onlyme();
}

int main()
{
    LOG("Hello World");
    Oh oh;
    command(&oh);
   // LOG("-------------------");
    //Yes ys();
    // command(&ys);  // Compile error
    LOG("-------------------");
    Ah ah;
    command(&ah); // garbage data

    return 0;

}
