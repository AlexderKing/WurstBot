#pragma once

#ifndef PINOUT_H_
#define PINOUT_H_

constexpr auto kpull_pin = 22;

constexpr auto kmotor_1_enable      = 31;
constexpr auto kmotor_1_direction   = 30;
constexpr auto kmotor_2_enable      = 33;
constexpr auto kmotor_2_direction   = 32;
constexpr auto kmotor_3_enable      = 35;
constexpr auto kmotor_3_direction   = 34;
constexpr auto kmotor_4_enable      = 37;
constexpr auto kmotor_4_direction   = 36;

constexpr auto kultrasonic_1_echo = 50;
constexpr auto kultrasonic_1_trig = 51;

constexpr auto kultrasonic_2_echo = 48;
constexpr auto kultrasonic_2_trig = 49;

constexpr auto kultrasonic_3_echo = 46;
constexpr auto kultrasonic_3_trig = 47;

constexpr auto kultrasonic_4_echo = 44;
constexpr auto kultrasonic_4_trig = 45;


#endif // PINOUT_H_
