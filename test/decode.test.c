#include <stdio.h>
#include <stdint.h>
#include "../src/mqttCodec.h"

int32_t currentSize = 0;
uint16_t failedAssertions = 0;
uint8_t callbackCounter = 0;

void itShouldDecodeAMessageWithA2ByteHeaderAndAZeroLengthRemainingSizeCallback(struct MqttMessage *m)
{
    callbackCounter++;

    if (currentSize != 2)
    {
        printf("Callback: Expected currentSize to be 2 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (m->size != 2)
    {
        printf("Callback: Expected size to be 2 but was %i\n", m->size);
        failedAssertions++;
    }

    if (m->fixedHeaderSize != 2)
    {
        printf("Callback: Expected fixedHeaderSize to be 2 but was %i\n", m->fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m->controlPacketType != 0x30)
    {
        printf("Callback: Expected controlPacketType to be 0x30 but was 0x%X\n", m->controlPacketType);
        failedAssertions++;
    }
        
    if (m->flags != 0x00)
    {
        printf("Callback: Expected flags to be 0x00 but was 0x%X\n", m->flags);
        failedAssertions++;
    }

    if (m->remainingSize != 0)
    {
        printf("Callback: Expected remainingSize to be 0 but was %i\n", m->remainingSize);
        failedAssertions++;
    }

    if (m->variableHeaderSize != 0)
    {
        printf("Callback: Expected variableHeaderSize to be 0 but was %i\n", m->variableHeaderSize);
        failedAssertions++;
    }

    if (m->variableHeader != 0)
    {
        printf("Callback: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m->variableHeader));
        failedAssertions++;
    }

    if (m->payloadSize != 0)
    {
        printf("Callback: Expected payloadSize to be 0 but was %i\n", m->payloadSize);
        failedAssertions++;
    }

    if (m->payload != 0)
    {
        printf("Callback: Expected payload to be 0x%X but was 0x%X\n", m->bytes[2], *(m->payload));
        failedAssertions++;
    }

    if (m->packetIdentifier != 0)
    {
        printf("Callback: Expected packetIdentifier to be 0 but was %i\n", m->packetIdentifier);
        failedAssertions++;
    }

    if (m->publishTopicNameSize != 0)
    {
        printf("Callback: Expected publishTopicNameSize to be 0 but was %i\n", m->publishTopicNameSize);
        failedAssertions++;
    }

    if (m->publishTopicName != 0)
    {
        printf("Callback: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }
}

static uint16_t itShouldDecodeAMessageWithA2ByteHeaderAndAZeroLengthRemainingSize()
{
    printf("It should decode a message with a 2 byte header and a zero length remaining size\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x00 };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 2;
    uint32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 2, itShouldDecodeAMessageWithA2ByteHeaderAndAZeroLengthRemainingSizeCallback);

    if (callbackCounter != 1)
    {
        printf("Expected callbackCounter to be 1 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 0)
    {
        printf("Expected currentSize to be 0 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 0)
    {
        printf("Expected messageSize to be 0 but was %i\n", messageSize);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

void itShouldDecodeAMessageWithA2ByteHeaderCallback(struct MqttMessage *m)
{
    callbackCounter++;

    if (currentSize != 3)
    {
        printf("Callback: Expected currentSize to be 3 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (m->size != 3)
    {
        printf("Callback: Expected size to be 3 but was %i\n", m->size);
        failedAssertions++;
    }

    if (m->fixedHeaderSize != 2)
    {
        printf("Callback: Expected fixedHeaderSize to be 2 but was %i\n", m->fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m->controlPacketType != 0x30)
    {
        printf("Callback: Expected controlPacketType to be 0x30 but was 0x%X\n", m->controlPacketType);
        failedAssertions++;
    }

    if (m->flags != 0x00)
    {
        printf("Callback: Expected flags to be 0x00 but was 0x%X\n", m->flags);
        failedAssertions++;
    }

    if (m->remainingSize != 1)
    {
        printf("Callback: Expected remainingSize to be 1 but was %i\n", m->remainingSize);
        failedAssertions++;
    }

    if (m->variableHeaderSize != 0)
    {
        printf("Callback: Expected variableHeaderSize to be 0 but was %i\n", m->variableHeaderSize);
        failedAssertions++;
    }

    if (m->variableHeader != 0)
    {
        printf("Callback: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m->variableHeader));
        failedAssertions++;
    }

    if (m->payloadSize != 0)
    {
        printf("Callback: Expected payloadSize to be 0 but was %i\n", m->payloadSize);
        failedAssertions++;
    }

    if (m->payload != &(m->bytes[2]))
    {
        printf("Callback: Expected payload to be 0x%X but was 0x%X\n", m->bytes[2], *(m->payload));
        failedAssertions++;
    }

    if (m->packetIdentifier != 0x00)
    {
        printf("Callback: Expected packetIdentifier to be 0x00 but was 0x%X\n", m->packetIdentifier);
        failedAssertions++;
    }

    if (m->publishTopicNameSize != 0)
    {
        printf("Callback: Expected publishTopicNameSize to be 0 but was %i\n", m->publishTopicNameSize);
        failedAssertions++;
    }

    if (m->publishTopicName != 0)
    {
        printf("Callback: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }
}

static uint16_t itShouldDecodeAMessageWithA2ByteHeader()
{
    printf("It should decode a message with a 2 byte header\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x01, 0xFF };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 3;
    uint32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 3, itShouldDecodeAMessageWithA2ByteHeaderCallback);

    if (callbackCounter != 1)
    {
        printf("Expected callbackCounter to be 1 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 0)
    {
        printf("Expected currentSize to be 0 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 0)
    {
        printf("Expected messageSize to be 0 but was %i\n", messageSize);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

void itShouldDecodeAMessageWithA3ByteHeaderCallback(struct MqttMessage *m)
{
    callbackCounter++;
}

static uint16_t itShouldDecodeAMessageWithA3ByteHeader()
{
    printf("It should decode a message with a 3 byte header\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x81, 0x02, 0xFF };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 4;
    int32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 4, itShouldDecodeAMessageWithA3ByteHeaderCallback);

    if (callbackCounter != 0)
    {
        printf("Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 4)
    {
        printf("Expected currentSize to be 4 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 260)
    {
        printf("Expected messageSize to be 260 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 4)
    {
        printf("Expected size to be 4 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 3)
    {
        printf("Expected fixedHeaderSize to be 3 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 257)
    {
        printf("Expected remainingSize to be 257 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Callback: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Callback: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Callback: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != &(m.bytes[3]))
    {
        printf("Callback: Expected payload to be 0x%X but was 0x%X\n", m.bytes[3], *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Callback: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Callback: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Callback: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

void itShouldDecodeAMessageWithA4ByteHeaderCallback(struct MqttMessage *m)
{
    callbackCounter++;
}

static uint16_t itShouldDecodeAMessageWithA4ByteHeader()
{
    printf("It should decode a message with a 4 byte header\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x81, 0x82, 0x03, 0xFF };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 5;
    int32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 5, itShouldDecodeAMessageWithA4ByteHeaderCallback);

    if (callbackCounter != 0)
    {
        printf("Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 5)
    {
        printf("Expected currentSize to be 5 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 49413)
    {
        printf("Expected messageSize to be 49413 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 5)
    {
        printf("Expected size to be 5 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 4)
    {
        printf("Expected fixedHeaderSize to be 4 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 49409)
    {
        printf("Expected remainingSize to be 49409 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Callback: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Callback: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Callback: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != &(m.bytes[4]))
    {
        printf("Callback: Expected payload to be 0x%X but was 0x%X\n", m.bytes[4], *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Callback: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Callback: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Callback: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

void itShouldDecodeAMessageWithA5ByteHeaderCallback(struct MqttMessage *m)
{
    callbackCounter++;
}

static uint16_t itShouldDecodeAMessageWithA5ByteHeader()
{
    printf("It should decode a message with a 5 byte header\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x81, 0x82, 0x83, 0x04, 0xFF };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 6;
    int32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 6, itShouldDecodeAMessageWithA5ByteHeaderCallback);

    if (callbackCounter != 0)
    {
        printf("Expected callbackCounter to be 1 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 6)
    {
        printf("Expected currentSize to be 6 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 8438022)
    {
        printf("Expected messageSize to be 8438022 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 6)
    {
        printf("Expected size to be 5 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 5)
    {
        printf("Expected fixedHeaderSize to be 5 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 8438017)
    {
        printf("Expected remainingSize to be 8438017 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Callback: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Callback: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Callback: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != &(m.bytes[5]))
    {
        printf("Callback: Expected payload to be 0x%X but was 0x%X\n", m.bytes[5], *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Callback: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Callback: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Callback: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

void itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback(struct MqttMessage *m)
{
    callbackCounter++;
}

static uint16_t itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunks()
{
    printf("It should decode a message with a 5 byte header given through 1 byte chunks\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x81, 0x82, 0x83, 0x04, 0xFF };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 1;
    int32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 1, itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback);

    if (callbackCounter != 0)
    {
        printf("Byte 1: Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 1)
    {
        printf("Byte 1: Expected currentSize to be 1 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 2)
    {
        printf("Byte 1: Expected messageSize to be 2 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 1)
    {
        printf("Byte 1: Expected size to be 1 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 2)
    {
        printf("Byte 1: Expected fixedHeaderSize to be 2 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Byte 1: Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Byte 1: Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 0)
    {
        printf("Byte 1: Expected remainingSize to be 0 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Byte 1: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Byte 1: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Byte 1: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != 0)
    {
        printf("Byte 1: Expected payload to be 0x%X but was 0x%X\n", 0, *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Byte 1: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Byte 1: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Byte 1: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    callbackCounter = 0;
    currentSize = 2;
    messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 1, itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback);

    if (callbackCounter != 0)
    {
        printf("Byte 2: Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 2)
    {
        printf("Byte 2: Expected currentSize to be 2 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 4)
    {
        printf("Byte 2: Expected messageSize to be 4 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 2)
    {
        printf("Byte 2: Expected size to be 2 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 3)
    {
        printf("Byte 2: Expected fixedHeaderSize to be 3 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Byte 2: Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Byte 2: Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 1)
    {
        printf("Byte 2: Expected remainingSize to be 1 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Byte 2: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Byte 2: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Byte 2: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != 0)
    {
        printf("Byte 2: Expected payload to be 0x%X but was 0x%X\n", 0, *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Byte 2: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Byte 2: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Byte 2: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    callbackCounter = 0;
    currentSize = 3;
    messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 1, itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback);

    if (callbackCounter != 0)
    {
        printf("Byte 3: Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 3)
    {
        printf("Byte 3: Expected currentSize to be 3 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 261)
    {
        printf("Byte 3: Expected messageSize to be 261 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 3)
    {
        printf("Byte 3: Expected size to be 3 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 4)
    {
        printf("Byte 3: Expected fixedHeaderSize to be 4 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Byte 3: Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Byte 3: Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 257)
    {
        printf("Byte 3: Expected remainingSize to be 257 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Byte 3: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Byte 3: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Byte 3: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != 0)
    {
        printf("Byte 3: Expected payload to be 0x%X but was 0x%X\n", 0, *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Byte 3: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Byte 3: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Byte 3: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    callbackCounter = 0;
    currentSize = 4;
    messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 1, itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback);

    if (callbackCounter != 0)
    {
        printf("Byte 4: Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 4)
    {
        printf("Byte 4: Expected currentSize to be 4 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 49414)
    {
        printf("Byte 4: Expected messageSize to be 49414 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 4)
    {
        printf("Byte 4: Expected size to be 4 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 5)
    {
        printf("Byte 4: Expected fixedHeaderSize to be 5 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.remainingSize != 49409)
    {
        printf("Byte 4: Expected remainingSize to be 49409 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.controlPacketType != 0x30)
    {
        printf("Byte 4: Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Byte 4: Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Byte 4: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Byte 4: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Byte 4: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != 0)
    {
        printf("Byte 4: Expected payload to be 0x%X but was 0x%X\n", 0, *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Byte 4: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Byte 4: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Byte 4: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    callbackCounter = 0;
    currentSize = 5;
    messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 1, itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback);

    if (callbackCounter != 0)
    {
        printf("Byte 5: Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 5)
    {
        printf("Byte 5: Expected currentSize to be 5 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 8438022)
    {
        printf("Byte 5: Expected messageSize to be 8438022 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 5)
    {
        printf("Byte 5: Expected size to be 5 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 5)
    {
        printf("Byte 5: Expected fixedHeaderSize to be 5 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Byte 5: Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Byte 5: Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 8438017)
    {
        printf("Byte 5: Expected remainingSize to be 8438017 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Byte 5: Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Byte 5: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Byte 5: Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != 0)
    {
        printf("Byte 5: Expected payload to be 0x%X but was 0x%X\n", 0, *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Byte 5: Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Byte 5: Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Byte 5: Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

void itShouldMoveTheBytesOfANewMessageToTheBeginningCallback(struct MqttMessage *m)
{
    callbackCounter++;

    if (callbackCounter == 2)
    {
        if (m->size != 4)
        {
            printf("Callback: Expected size to be 4 but was %i\n", m->size);
            failedAssertions++;
        }

        if (m->fixedHeaderSize != 2)
        {
            printf("Callback: Expected fixedHeaderSize to be 2 but was %i\n", m->fixedHeaderSize);
            failedAssertions++;
        }
        
        if (m->controlPacketType != 0x30)
        {
            printf("Callback: Expected controlPacketType to be 0x30 but was 0x%X\n", m->controlPacketType);
            failedAssertions++;
        }

        if (m->flags != 0x00)
        {
            printf("Callback: Expected flags to be 0x00 but was 0x%X\n", m->flags);
            failedAssertions++;
        }

        if (m->remainingSize != 2)
        {
            printf("Callback: Expected remainingSize to be 2 but was %i\n", m->remainingSize);
            failedAssertions++;
        }

        if (m->variableHeaderSize != 0)
        {
            printf("Callback: Expected variableHeaderSize to be 0 but was %i\n", m->variableHeaderSize);
            failedAssertions++;
        }

        if (m->variableHeader != 0)
        {
            printf("Callback: Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m->variableHeader));
            failedAssertions++;
        }

        if (m->payloadSize != 0)
        {
            printf("Callback: Expected payloadSize to be 0 but was %i\n", m->payloadSize);
            failedAssertions++;
        }

        if (m->payload != 0)
        {
            printf("Callback: Expected payload to be 0x%X but was 0x%X\n", 0, *(m->payload));
            failedAssertions++;
        }

        if (m->packetIdentifier != 0x00)
        {
            printf("Callback: Expected packetIdentifier to be 0x00 but was 0x%X\n", m->packetIdentifier);
            failedAssertions++;
        }

        if (m->publishTopicNameSize != 0)
        {
            printf("Callback: Expected publishTopicNameSize to be 0 but was %i\n", m->publishTopicNameSize);
            failedAssertions++;
        }

        if (m->publishTopicName != 0)
        {
            printf("Callback: Expected publishTopicName to be 0\n");
            failedAssertions++;
        }
    }
}

static uint16_t itShouldMoveTheBytesOfANewMessageToTheBeginning()
{
    printf("It should move the bytes of a new message to the beginning\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t bytes[10] = { 0x30, 0x01, 0xAA, 0x30, 0x02, 0xBB, 0xBB };
    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    currentSize = 7;
    int32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 7, itShouldMoveTheBytesOfANewMessageToTheBeginningCallback);

    if (callbackCounter != 2)
    {
        printf("Expected callbackCounter to be 2 but was %i\n", callbackCounter);
        failedAssertions++;
    }
    
    if (currentSize != 0)
    {
        printf("Expected currentSize to be 0 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 0)
    {
        printf("Expected messageSize to be 0 but was %i\n", messageSize);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldDecodeConnect()
{
    printf("It should decode connect\n");
    failedAssertions = 0;
    callbackCounter = 0;

    uint8_t clientIdentifier[] = "C";
    uint8_t willTopic[] = "TO";
    uint8_t willMessage[] = "MES";
    uint8_t userName[] = "USER";
    uint8_t password[] = "PASSW";

    struct MqttConnectParameter parameter = {
        .clientIdentifier = clientIdentifier,
        .clientIdentifierSize = 1,
        .cleanSession = 1,
        .willTopic = willTopic,
        .willTopicSize = 2,
        .willMessage = willMessage,
        .willMessageSize = 3,
        .willQos = MQTT_CONNECT_VARIABLE_HEADER_CONNECT_FLAG_WILL_QOS_EXACTLY_ONCE,
        .willRetain = 1,
        .userName = userName,
        .userNameSize = 4,
        .password = password,
        .passwordSize = 5,
        .keepAlive = 0xAABB
    };

    uint8_t bytes[37];
    uint32_t size = encodeMqttConnect(&parameter, bytes);

    struct MqttMessage m =
    {
        .bytes = bytes,
        .size = 0
    };

    callbackCounter = 0;
    currentSize = 36;
    uint32_t messageSize = decodeMqttChunk(&m, &currentSize, (int32_t) 36, itShouldDecodeAMessageWithA5ByteHeaderGivenThrough1ByteChunksCallback);

    if (callbackCounter != 0)
    {
        printf("Expected callbackCounter to be 0 but was %i\n", callbackCounter);
        failedAssertions++;
    }

    if (currentSize != 5)
    {
        printf("Expected currentSize to be 5 but was %i\n", currentSize);
        failedAssertions++;
    }

    if (messageSize != 8438022)
    {
        printf("Expected messageSize to be 8438022 but was %i\n", messageSize);
        failedAssertions++;
    }

    if (m.size != 5)
    {
        printf("Expected size to be 5 but was %i\n", m.size);
        failedAssertions++;
    }

    if (m.fixedHeaderSize != 5)
    {
        printf("Expected fixedHeaderSize to be 5 but was %i\n", m.fixedHeaderSize);
        failedAssertions++;
    }
    
    if (m.controlPacketType != 0x30)
    {
        printf("Expected controlPacketType to be 0x30 but was 0x%X\n", m.controlPacketType);
        failedAssertions++;
    }

    if (m.flags != 0x00)
    {
        printf("Expected flags to be 0x00 but was 0x%X\n", m.flags);
        failedAssertions++;
    }

    if (m.remainingSize != 8438017)
    {
        printf("Expected remainingSize to be 8438017 but was %i\n", m.remainingSize);
        failedAssertions++;
    }

    if (m.variableHeaderSize != 0)
    {
        printf("Expected variableHeaderSize to be 0 but was %i\n", m.variableHeaderSize);
        failedAssertions++;
    }

    if (m.variableHeader != 0)
    {
        printf("Expected variableHeader to be 0x%X but was 0x%X\n", 0, *(m.variableHeader));
        failedAssertions++;
    }

    if (m.payloadSize != 0)
    {
        printf("Expected payloadSize to be 0 but was %i\n", m.payloadSize);
        failedAssertions++;
    }

    if (m.payload != 0)
    {
        printf("Expected payload to be 0x%X but was 0x%X\n", 0, *(m.payload));
        failedAssertions++;
    }

    if (m.packetIdentifier != 0x00)
    {
        printf("Expected packetIdentifier to be 0x00 but was 0x%X\n", m.packetIdentifier);
        failedAssertions++;
    }

    if (m.publishTopicNameSize != 0)
    {
        printf("Expected publishTopicNameSize to be 0 but was %i\n", m.publishTopicNameSize);
        failedAssertions++;
    }

    if (m.publishTopicName != 0)
    {
        printf("Expected publishTopicName to be 0\n");
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}