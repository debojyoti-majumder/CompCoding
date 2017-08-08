class StateMachine {
};

// Throw an exception to indicate an invalid operation
class IState {
  public:
    void start() = 0;
    void stop() = 0;
    void resume() = 0;
    void pause() = 0;
};

class RunningState : public IState {
};

class PausedState : public IState {
};

class StopedState : public IState {
};
