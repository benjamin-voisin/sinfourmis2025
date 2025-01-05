#pragma once

#include "game/constants.hpp"
#include "map/edge.hpp"
#include "nlohmann/json.hpp"
#include "salle_parser.hpp"
#include "sinfourmis.h"
#include <memory>
#include <unordered_set>
#include <iostream>

using json = nlohmann::json;

class Ant;
class Edge;

class Node {
  public:
    Node() = default;
    ~Node() = default;

    // for json serialization / deserialization
    friend void to_json(json &j, const Node &node);
	friend void from_json(const json &j, Node &node);

    /**
     * @brief Convert the node to a salle that can be sent to the ants simulation
     *
     * @return salle the salle representation of the node
     */
    salle as_salle() const;

    /**
     * @brief Add an edge from this node to another node. It is undirected so the other node will
     * also have an edge to this node.
     *
     * @param other the node to add an edge to
	 * @param life the life of the edge
     */
    void add_edge(Node &other, unsigned int life);

    /**
     * @brief Add an ant to the node as a visitor
     *
     * @param ant the ant to add
     */
    void add_ant(Ant *ant);

    /**
     * @brief Remove an ant from the node
     *
     * @param ant the ant to remove
     */
    void remove_ant(Ant *ant);

    /**
     * @param id the id of the edge to get
     * @return Edge* the edge with the given id
     */
    Edge *get_edge(unsigned int id) const;

    /**
     * @param node the node to get the edge to
     * @return Edge* the edge to the given node
     */
    unsigned int get_id_to(const Node *node) const;

    /**
     * @brief remove `max_food` food from the node
     *
     * @param max_food the maximum amount of food to gather
     * @return unsigned int the actual amount of food gathered
     */
    unsigned int gather_food(unsigned int max_food);

    /**
     * @brief Regenerate food on the node by `NODE_FOOD_REGEN`
     *
     */
    void regen_food();

    void set_pheromone(uint8_t pheromone) {
        this->pheromone = pheromone;
    }

    unsigned int get_id() const {
        return id;
    }
    std::vector<std::shared_ptr<Edge>> get_edges() const {
        return edges;
    }
    std::vector<std::shared_ptr<Edge>> &get_edges() {
        return edges;
    }

	const std::unordered_set<Ant *> &get_ants() const {
		return ants;
	}

    salle_type get_type() const {
        return type;
    }

	unsigned int get_food() const {
		if (type != salle_type::NOURRITURE) {
			throw std::runtime_error("Node is not a food node");
		}
		return food;
	}

	unsigned int get_max_food() const {
		if (type != salle_type::NOURRITURE) {
			throw std::runtime_error("Node is not a food node");
		}
		return max_food;
	}

    size_t degree() const {
        return edges.size();
    }

    std::pair<float, float> get_position() const {
        return {x, y};
    }

    std::unordered_set<Ant *> &get_ants() {
        return ants;
    }

  private:
    void remove_edge(const std::shared_ptr<Edge> &edge);

    unsigned int id = 0;
    salle_type type = salle_type::VIDE;
    float x = 0;
    float y = 0;
    uint8_t pheromone = 0;


    unsigned int food = 0;
	unsigned int regen = 0;
	unsigned int max_food = 0;
	int total_available = 0;

    std::vector<std::shared_ptr<Edge>> edges;
    std::unordered_set<Ant *> ants;
};