#ifndef __JSON_EXPORTER_HPP__
#define __JSON_EXPORTER_HPP__

#include "Node.hpp"
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class JsonExporter {
  public:
    JsonExporter() {}

    template <typename T> static std::string arrayToJson(T array[], uint size) {
        std::string str;
        str += arrayCharBegin + std::to_string(array[0]);
        uint i = 1;

        while (i < size) {
            str += arrayCharDelimiter + std::to_string(array[i++]);
        }

        return str + arrayCharEnd;
    }

    template <typename T> static std::string vectorToJson(std::vector<T> v) {
        std::string str;
        str += arrayCharBegin;

        for (auto &elem : v) {
            str += std::to_string(elem);
            if (v.back() != elem) {
                str += arrayCharDelimiter;
            }
        }

        return str + arrayCharEnd;
    }

    template <typename T>
    static std::string mapToJson(std::map<std::string, T> map) {
        std::string str;
        str += objCharBegin;
        std::string lastKey = (--map.begin())->first;

        for (auto const &pair : map) {
            str += "\"" + pair.first + "\":" + std::to_string(pair.second);
            if (lastKey.compare(pair.first)) {
                continue;
            }
            str += objCharDelimiter;
        }

        return str + objCharEnd;
    }

  protected:
    static const char arrayCharBegin = '[';
    static const char arrayCharEnd = ']';
    static const char arrayCharDelimiter = ',';

    static const char objCharBegin = '{';
    static const char objCharEnd = '}';
    static const char objCharDelimiter = ',';

    template <class T = Node<>> static void DFS(T *origin, void (*function)()) {
        T *_node = origin;
        T *_parent = origin;
        do {
            while (_node->hasLeftChild()) {
                _parent = _node;
                _node = _node->getLeftChild();
            }
            while (_node->hasRightChild()) {
                _parent = _node;
                _node = _node->getRightChild();
            }
            (*function)(_node);
            _node = _parent;
            _parent = _node->getParent();
        } while (_node != origin || _node->hasRightChild());
    }
};

#endif