/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PID_H_
#define PID_H_
#include <iostream>

/**
     * PID(proportion integral differential)
     *
     * Proportional
     * the obvious method is proportional control: the motor current is set in
 * proportion to the existing error.
     * However, this method fails if, for instance, the arm has to lift
 * different weights:
     * a greater weight needs a greater force applied for a same error on the
 * down side,
     * but a smaller force if the error is on the upside. That's where the
 * integral and derivative terms play their part.
     * Integral
     * an integral term increases action in relation not only
     * to the error but also the time for which it has persisted.
     * So, if applied force is not enough to bring the error to zero, this force
 * will be increased as time passes.
     * A pure "I" controller could bring the error to zero, however, it would be
 * both slow reacting at the start
     * (because action would be small at the beginning, needing time to get
 * significant) and brutal
     * (the action increases as long as the error is positive, even if the error
 * has started to approach zero).
     * Derivative
     * A derivative term does not consider the error (meaning it cannot bring it
 * to zero: a pure D controller
     * cannot bring the system to its setpoint), but the rate of change of
 * error, trying to bring this rate to zero.
     * It aims at flattening the error trajectory into a horizontal line,
 * damping the force applied, and so reduces
     * overshoot (error on the other side because too great applied force).
 * Applying too much impetus when the error
     * is small and decreasing will lead to overshoot. After overshooting, if
 * the controller were to apply a large
     * correction in the opposite direction and repeatedly overshoot the desired
 * position, the output would
     * oscillate around the setpoint in either a constant, growing, or decaying
 * sinusoid. If the amplitude of the
     * oscillations increases with time, the system is unstable. If they
 * decrease, the system is stable. If the
     * oscillations remain at a constant magnitude, the system is marginally
 * stable.
     * @param kp the coefficient of Proportional.
     * @param ki the coefficient of Integral.
     * @param kd the coefficient of Derivative.
     * @prram currError current error of the system that wanted to adjust.
     * @param deviation system fixed deviation.
     */

class pid {
 public:
  pid(double kp = 0.5, double ki = 0.01, double kd = 0.01,
      double currError = 0.8, double deviation = 0.1);
  void iterater();
  void loop(int n = 10);

 private:
  double _kp;
  double _ki;
  double _kd;
  double _prevError;
  double _currError;
  double _deviation;
  double _integral;
  double _u;
  double _differential;
  double _total;
};
#endif  // PID_H_