#include "game/queen.hpp"

const unsigned int Queen::upgrade_costs[5] = {QUEEN_UPGRADE_LIFE_COST, QUEEN_UPGRADE_WATER_COST,
                                              QUEEN_UPGRADE_FOOD_COST, QUEEN_UPGRADE_ATTACK_COST,
                                              QUEEN_UPGRADE_NB_ANT_COST};

void Queen::game_turn() {
    if (waiting_upgrade > 0) {
        waiting_upgrade--;
    }
}

bool Queen::can_perform_action() const {
    return waiting_upgrade == 0;
}

bool Queen::upgrade(Stat type) {
    if (waiting_upgrade > 0) {
        return false;
    }
    if (victory_points < upgrade_costs[(unsigned int)type]) {
        return false;
    }
    stats[(unsigned int)type]++;
    victory_points -= upgrade_costs[(unsigned int)type];
    waiting_upgrade = QUEEN_ACTION_TIME;
    return true;
}

unsigned int Queen::get_stat(Stat type) const {
    return stats[(unsigned int)type];
}
