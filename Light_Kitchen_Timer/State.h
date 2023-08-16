class State {
  protected:
    KitchenTimer *kt_;
  public:
    virtual ~State()
    virtual std::string 

    void set_kt(KitchenTimer *kt) {
      this->kt_ = kt;
    }

    vitrual void Handle1() = 0;
    virtual void Handle2() = 0;
}