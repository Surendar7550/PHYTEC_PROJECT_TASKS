#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 100

// === States ===
typedef enum {
    IDLE,
    RECEIVING,
    PROCESSING,
    SENDING_ACK
} State;

// === Events ===
typedef enum {
    EVENT_MSG_START,
    EVENT_BYTE_RECEIVED,
    EVENT_MSG_COMPLETE,
    EVENT_PROCESS_OK,
    EVENT_PROCESS_FAIL,
    EVENT_ACK_SENT
} Event;

// === Global Variables ===
State current_state = IDLE;
char buffer[MAX_MSG_LEN];
int buffer_pos = 0;

// === Helper Functions ===

// Reset buffer for new message
void init_buffer() {
    memset(buffer, 0, MAX_MSG_LEN);
    buffer_pos = 0;
}

// Simulate storing a byte
void store_byte(char byte) {
    if (buffer_pos < MAX_MSG_LEN - 1) {
        buffer[buffer_pos++] = byte;
    }
}

// Validate message (e.g., must start with "HELLO")
int validate_message() {
    if (strncmp(buffer, "HELLO", 5) == 0) {
        printf("Message validated: %s\n", buffer);
        return 1; // OK
    } else {
        printf("Invalid message: %s\n", buffer);
        return 0; // Fail
    }
}

// Prepare and send ACK
void prepare_ack() {
    printf("Sending: ACK\\n\n");
}

// Log error
void log_error() {
    printf("Error: Invalid message!\n");
}

// === Event handler ===
void handle_event(Event event, char byte) {
    switch (current_state) {
        case IDLE:
            if (event == EVENT_MSG_START) {
                printf("IDLE -> RECEIVING\n");
                init_buffer();
                current_state = RECEIVING;
            }
            break;

        case RECEIVING:
            if (event == EVENT_BYTE_RECEIVED) {
                store_byte(byte);
                if (byte == '\n') {
                    current_state = PROCESSING;
                    if (validate_message()) {
                        handle_event(EVENT_PROCESS_OK, 0);
                    } else {
                        handle_event(EVENT_PROCESS_FAIL, 0);
                    }
                }
            }
            break;

        case PROCESSING:
            if (event == EVENT_PROCESS_OK) {
                printf("PROCESSING -> SENDING_ACK\n");
                prepare_ack();
                current_state = SENDING_ACK;
                handle_event(EVENT_ACK_SENT, 0);
            } else if (event == EVENT_PROCESS_FAIL) {
                log_error();
                current_state = IDLE;
            }
            break;

        case SENDING_ACK:
            if (event == EVENT_ACK_SENT) {
                printf("SENDING_ACK -> IDLE\n");
                current_state = IDLE;
            }
            break;

        default:
            break;
    }
}

// === Simulate incoming bytes ===
void simulate_receive(const char *msg) {
    handle_event(EVENT_MSG_START, 0); // Start message
    for (int i = 0; msg[i] != '\0'; i++) {
        handle_event(EVENT_BYTE_RECEIVED, msg[i]);
    }
}

// === Main ===
int main() {
    printf("=== Simple Event-driven State Machine ===\n");

    // Valid message
    simulate_receive("HELLO\n");

    // Invalid message
    simulate_receive("BYE\n");

    return 0;
}
