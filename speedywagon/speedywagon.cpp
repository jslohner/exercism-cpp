#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* sensor) {
    if (sensor != nullptr) return true;
    return false;
}

int activity_counter(pillar_men_sensor* sensors, int capacity) {
    if (sensors == nullptr) return 0;
    int total_activity = 0;
    for (int i = 0; i < capacity; ++i) {
        total_activity += sensors[i].activity;
    }
    return total_activity;
}

bool alarm_control(pillar_men_sensor* sensor) {
    if (sensor == nullptr) return false;
    return sensor->activity > 0;
}

bool uv_alarm(pillar_men_sensor* sensor) {
    if (sensor == nullptr) return false;
    int uv_value = uv_light_heuristic(&sensor->data);
    return uv_value > sensor->activity;
}

}  // namespace speedywagon
