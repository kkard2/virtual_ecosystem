#include "user_action_parser.h"

auto UserActionParser::parse(const std::string &text) -> std::optional<UserAction> {
    if (text.empty()) {
        return std::nullopt;
    }

    // parse beginning as a number
    size_t count = 0;

    for (auto c : text) {
        if (std::isdigit(c)) {
            count = count * 10 + (c - '0');
        } else {
            break;
        }
    }

    if (count == 0) {
        count = 1;
    }

    auto last_char = text.back();

    if (std::isdigit(last_char)) {
        return std::nullopt;
    }

    switch (last_char) {
    case 'h':
        return UserAction(UserActionType::HELP, count);
    case 'q':
        return UserAction(UserActionType::QUIT, count);
    case ',':
        return UserAction(UserActionType::STEP_FORWARD, count);
    case '.':
        return UserAction(UserActionType::STEP_BACK, count);
    default:
        return UserAction(UserActionType::INVALID, count);
    }
}
