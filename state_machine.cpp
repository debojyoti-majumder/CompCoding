
class StopWatchStateMachine {
  private:
    int counter
  public:
    void start();
    void start(int data);
    
    void getTickcount();
    void setTickGranularity();
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
