class Duck {
    constructor() {
       let quackBehavior;
    }

    performQuack() {
        this.quackBehavior();
    }
    
    setQuackBehavior(f) {
        this.quackBehavior = f;
    }
};

const quack = () => {
    console.log("ガーガー");
}

const muteQuack = () => {
        console.log("<沈黙>");
}

class MallardDuck extends Duck {
    constructor() {
        super();
        this.quackBehavior = quack;
    }
};

{
    const mallard = new MallardDuck();
    mallard.performQuack();
    mallard.setQuackBehavior(muteQuack);
    mallard.performQuack();
}