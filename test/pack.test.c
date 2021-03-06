#include <stdio.h>
#include <stdint.h>
#include "../include/mqtt_packer.h"

static uint16_t itShouldPackTheRemainingLengthWith1Byte()
{
    printf("It should pack the remaining length with 1 byte\n");

    uint8_t bytes[2];
    uint32_t size = packMqttRemainingLength(bytes, 127);
    uint16_t failedAssertions = 0;

    if (size != 1)
    {
        printf("Expected size to be 1 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0x7F)
    {
        printf("Expected byte[0] to be 0x7F but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackTheRemainingLengthWith2Bytes()
{
    printf("It should pack the remaining length with 2 bytes\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[3];
    uint32_t size = packMqttRemainingLength(bytes, 128);

    if (size != 2)
    {
        printf("Remaining length 128: Expected size to be 2 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0x80)
    {
        printf("Remaining length 128: Expected byte[0] to be 0x80 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    if (bytes[1] != 0x01)
    {
        printf("Remaining length 128: Expected byte[1] to be 0x01 but was 0x%X\n", bytes[1]);
        failedAssertions++;
    }

    size = packMqttRemainingLength(bytes, 16383);

    if (size != 2)
    {
        printf("Remaining length 16383: Expected size to be 2 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0xFF)
    {
        printf("Remaining length 16383: Expected byte[0] to be 0xFF but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    if (bytes[1] != 0x7F)
    {
        printf("Remaining length 16383: Expected byte[1] to be 0x7F but was 0x%X\n", bytes[1]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackTheRemainingLengthWith3Bytes()
{
    printf("It should pack the remaining length with 3 bytes\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[4];
    uint32_t size = packMqttRemainingLength(bytes, 16384);

    if (size != 3)
    {
        printf("Remaining length 16384: Expected size to be 3 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0x80)
    {
        printf("Remaining length 16384: Expected byte[0] to be 0x80 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    if (bytes[1] != 0x80)
    {
        printf("Remaining length 16384: Expected byte[1] to be 0x80 but was 0x%X\n", bytes[1]);
        failedAssertions++;
    }

    if (bytes[2] != 0x01)
    {
        printf("Remaining length 16384: Expected byte[2] to be 0x01 but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    size = packMqttRemainingLength(bytes, 2097151);

    if (size != 3)
    {
        printf("Remaining length 2097151: Expected size to be 3 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0xFF)
    {
        printf("Remaining length 2097151: Expected byte[0] to be 0x80 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    if (bytes[1] != 0xFF)
    {
        printf("Remaining length 2097151: Expected byte[1] to be 0xFF but was 0x%X\n", bytes[1]);
        failedAssertions++;
    }

    if (bytes[2] != 0x7F)
    {
        printf("Remaining length 2097151: Expected byte[2] to be 0x7F but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackTheRemainingLengthWith4Bytes()
{
    printf("It should pack the remaining length with 4 bytes\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[5];
    uint32_t size = packMqttRemainingLength(bytes, 2097152);

    if (size != 4)
    {
        printf("Expected size to be 4 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0x80)
    {
        printf("Expected byte[0] to be 0x80 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    if (bytes[1] != 0x80)
    {
        printf("Expected byte[1] to be 0x80 but was 0x%X\n", bytes[1]);
        failedAssertions++;
    }

    if (bytes[2] != 0x80)
    {
        printf("Expected byte[2] to be 0x80 but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    if (bytes[3] != 0x01)
    {
        printf("Expected byte[3] to be 0x01 but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    size = packMqttRemainingLength(bytes, 268435455);

    if (size != 4)
    {
        printf("Expected size to be 4 but was %i\n", size);
        failedAssertions++;
    }

    if (bytes[0] != 0xFF)
    {
        printf("Expected byte[0] to be 0x80 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    if (bytes[1] != 0xFF)
    {
        printf("Expected byte[1] to be 0xFF but was 0x%X\n", bytes[1]);
        failedAssertions++;
    }

    if (bytes[2] != 0xFF)
    {
        printf("Expected byte[2] to be 0xFF but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    if (bytes[3] != 0x7F)
    {
        printf("Expected byte[3] to be 0x7F but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackConnect()
{
    printf("It should pack CONNECT\n");
    uint16_t failedAssertions = 0;

    uint8_t clientIdentifier[] = "C";
    uint8_t willTopic[] = "TO";
    uint8_t willMessage[] = "MES";
    uint8_t userName[] = "USER";
    uint8_t password[] = "PASSW";

    struct MqttConnectPacket packet = {
        .clientIdentifier = clientIdentifier,
        .clientIdentifierSize = 1,
        .cleanSession = 1,
        .willTopic = willTopic,
        .willTopicSize = 2,
        .willMessage = willMessage,
        .willMessageSize = 3,
        .willQos = MQTT_QOS_EXACTLY_ONCE,
        .willRetain = 1,
        .userName = userName,
        .userNameSize = 4,
        .password = password,
        .passwordSize = 5,
        .keepAlive = 0xAABB
    };

    uint8_t bytes[37];
    uint32_t size = packMqttConnect(bytes, &packet);

    if (size != 37)
    {
        printf("Expected size to be 37 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x10)
    {
        printf("Expected byte[0] to be 0x10 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 35)
    {
        printf("Expected byte[1] to be 35 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Length MSB
    if (bytes[2] != 0x00)
    {
        printf("Expected byte[2] to be 0x00 but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Length LSB
    if (bytes[3] != 0x04)
    {
        printf("Expected byte[3] to be 0x04 but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    // Variable header - Protocol name - M
    if (bytes[4] != 0x4D)
    {
        printf("Expected byte[4] to be 0x4D but was 0x%X\n", bytes[4]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Q
    if (bytes[5] != 0x51)
    {
        printf("Expected byte[5] to be 0x51 but was 0x%X\n", bytes[5]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Q
    if (bytes[6] != 0x54)
    {
        printf("Expected byte[6] to be 0x54 but was 0x%X\n", bytes[6]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Q
    if (bytes[7] != 0x54)
    {
        printf("Expected byte[7] to be 0x54 but was 0x%X\n", bytes[7]);
        failedAssertions++;
    }

    // Variable header - Protocol version
    if (bytes[8] != 0x04)
    {
        printf("Expected byte[8] to be 0x04 but was 0x%X\n", bytes[8]);
        failedAssertions++;
    }

    // Variable header - Connect flags
    if (bytes[9] != 0xF6)
    {
        printf("Expected byte[9] to be 0xF6 but was 0x%X\n", bytes[9]);
        failedAssertions++;
    }

    // Variable header - Keep alive MSB
    if (bytes[10] != 0xAA)
    {
        printf("Expected byte[10] to be 0xAA but was 0x%X\n", bytes[10]);
        failedAssertions++;
    }

    // Variable header - Keep alive LSB
    if (bytes[11] != 0xBB)
    {
        printf("Expected byte[11] to be 0xBB but was 0x%X\n", bytes[11]);
        failedAssertions++;
    }

    // Payload - Client identifier - Length MSB
    if (bytes[12] != 0x00)
    {
        printf("Expected byte[12] to be 0x00 but was 0x%X\n", bytes[12]);
        failedAssertions++;
    }

    // Payload - Client identifier - Length LSB
    if (bytes[13] != 0x01)
    {
        printf("Expected byte[13] to be 0x01 but was 0x%X\n", bytes[13]);
        failedAssertions++;
    }

    // Payload - Client identifier - C
    if (bytes[14] != 0x43)
    {
        printf("Expected byte[14] to be 0x43 but was 0x%X\n", bytes[14]);
        failedAssertions++;
    }

    // Payload - Will topic - Length MSB
    if (bytes[15] != 0x00)
    {
        printf("Expected byte[15] to be 0x00 but was 0x%X\n", bytes[15]);
        failedAssertions++;
    }

    // Payload - Will topic - Length LSB
    if (bytes[16] != 0x02)
    {
        printf("Expected byte[16] to be 0x02 but was 0x%X\n", bytes[16]);
        failedAssertions++;
    }

    // Payload - Will topic - T
    if (bytes[17] != 0x54)
    {
        printf("Expected byte[17] to be 0x54 but was 0x%X\n", bytes[17]);
        failedAssertions++;
    }

    // Payload - Will topic - O
    if (bytes[18] != 0x4F)
    {
        printf("Expected byte[18] to be 0x4F but was 0x%X\n", bytes[18]);
        failedAssertions++;
    }

    // Payload - Will message - Length MSB
    if (bytes[19] != 0x00)
    {
        printf("Expected byte[19] to be 0x00 but was 0x%X\n", bytes[19]);
        failedAssertions++;
    }

    // Payload - Will message - Length LSB
    if (bytes[20] != 0x03)
    {
        printf("Expected byte[20] to be 0x03 but was 0x%X\n", bytes[20]);
        failedAssertions++;
    }

    // Payload - Will message - M
    if (bytes[21] != 0x4D)
    {
        printf("Expected byte[21] to be 0x4D but was 0x%X\n", bytes[21]);
        failedAssertions++;
    }

    // Payload - Will message - E
    if (bytes[22] != 0x45)
    {
        printf("Expected byte[22] to be 0x45 but was 0x%X\n", bytes[22]);
        failedAssertions++;
    }

    // Payload - Will message - S
    if (bytes[23] != 0x53)
    {
        printf("Expected byte[23] to be 0x53 but was 0x%X\n", bytes[23]);
        failedAssertions++;
    }

    // Payload - User name - Length MSB
    if (bytes[24] != 0x00)
    {
        printf("Expected byte[24] to be 0x00 but was 0x%X\n", bytes[24]);
        failedAssertions++;
    }

    // Payload - User name - Length LSB
    if (bytes[25] != 0x04)
    {
        printf("Expected byte[25] to be 0x04 but was 0x%X\n", bytes[25]);
        failedAssertions++;
    }

    // Payload - User name - U
    if (bytes[26] != 0x55)
    {
        printf("Expected byte[26] to be 0x55 but was 0x%X\n", bytes[26]);
        failedAssertions++;
    }

    // Payload - User name - S
    if (bytes[27] != 0x53)
    {
        printf("Expected byte[27] to be 0x53 but was 0x%X\n", bytes[27]);
        failedAssertions++;
    }

    // Payload - User name - E
    if (bytes[28] != 0x45)
    {
        printf("Expected byte[28] to be 0x45 but was 0x%X\n", bytes[28]);
        failedAssertions++;
    }

    // Payload - User name - R
    if (bytes[29] != 0x52)
    {
        printf("Expected byte[29] to be 0x52 but was 0x%X\n", bytes[29]);
        failedAssertions++;
    }

    // Payload - Password - Length MSB
    if (bytes[30] != 0x00)
    {
        printf("Expected byte[30] to be 0x00 but was 0x%X\n", bytes[30]);
        failedAssertions++;
    }

    // Payload - Password - Length LSB
    if (bytes[31] != 0x05)
    {
        printf("Expected byte[31] to be 0x05 but was 0x%X\n", bytes[31]);
        failedAssertions++;
    }

    // Payload - Password - P
    if (bytes[32] != 0x50)
    {
        printf("Expected byte[32] to be 0x50 but was 0x%X\n", bytes[32]);
        failedAssertions++;
    }

    // Payload - Password - A
    if (bytes[33] != 0x41)
    {
        printf("Expected byte[33] to be 0x41 but was 0x%X\n", bytes[33]);
        failedAssertions++;
    }

    // Payload - Password - S
    if (bytes[34] != 0x53)
    {
        printf("Expected byte[34] to be 0x53 but was 0x%X\n", bytes[34]);
        failedAssertions++;
    }

    // Payload - Password - S
    if (bytes[35] != 0x53)
    {
        printf("Expected byte[35] to be 0x53 but was 0x%X\n", bytes[35]);
        failedAssertions++;
    }

    // Payload - Password - W
    if (bytes[36] != 0x57)
    {
        printf("Expected byte[36] to be 0x57 but was 0x%X\n", bytes[36]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackConnectWithClientIdentifierSizeOf0()
{
    printf("It should pack CONNECT with a client identifier size of 0\n");
    uint16_t failedAssertions = 0;

    struct MqttConnectPacket packet = {
        .clientIdentifier = 0,
        .clientIdentifierSize = 0,
        .cleanSession = 0,
        .willTopic = 0,
        .willTopicSize = 0,
        .willMessage = 0,
        .willMessageSize = 0,
        .willQos = 0,
        .willRetain = 0,
        .userName = 0,
        .userNameSize = 0,
        .password = 0,
        .passwordSize = 0,
        .keepAlive = 0xAABB
    };

    uint8_t bytes[14];
    uint32_t size = packMqttConnect(bytes, &packet);

    if (size != 14)
    {
        printf("Expected size to be 14 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x10)
    {
        printf("Expected byte[0] to be 0x10 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 12)
    {
        printf("Expected byte[1] to be 12 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Length MSB
    if (bytes[2] != 0x00)
    {
        printf("Expected byte[2] to be 0x00 but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Length LSB
    if (bytes[3] != 0x04)
    {
        printf("Expected byte[3] to be 0x04 but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    // Variable header - Protocol name - M
    if (bytes[4] != 0x4D)
    {
        printf("Expected byte[4] to be 0x4D but was 0x%X\n", bytes[4]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Q
    if (bytes[5] != 0x51)
    {
        printf("Expected byte[5] to be 0x51 but was 0x%X\n", bytes[5]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Q
    if (bytes[6] != 0x54)
    {
        printf("Expected byte[6] to be 0x54 but was 0x%X\n", bytes[6]);
        failedAssertions++;
    }

    // Variable header - Protocol name - Q
    if (bytes[7] != 0x54)
    {
        printf("Expected byte[7] to be 0x54 but was 0x%X\n", bytes[7]);
        failedAssertions++;
    }

    // Variable header - Protocol version
    if (bytes[8] != 0x04)
    {
        printf("Expected byte[8] to be 0x04 but was 0x%X\n", bytes[8]);
        failedAssertions++;
    }

    // Variable header - Connect flags
    if (bytes[9] != 0x02)
    {
        printf("Expected byte[9] to be 0x02 but was 0x%X\n", bytes[9]);
        failedAssertions++;
    }

    // Variable header - Keep alive MSB
    if (bytes[10] != 0xAA)
    {
        printf("Expected byte[10] to be 0xAA but was 0x%X\n", bytes[10]);
        failedAssertions++;
    }

    // Variable header - Keep alive LSB
    if (bytes[11] != 0xBB)
    {
        printf("Expected byte[11] to be 0xBB but was 0x%X\n", bytes[11]);
        failedAssertions++;
    }

    // Payload - Client identifier - Length MSB
    if (bytes[12] != 0x00)
    {
        printf("Expected byte[12] to be 0x00 but was 0x%X\n", bytes[12]);
        failedAssertions++;
    }

    // Payload - Client identifier - Length LSB
    if (bytes[13] != 0x00)
    {
        printf("Expected byte[13] to be 0x00 but was 0x%X\n", bytes[13]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackPublish()
{
    printf("It should pack PUBLISH\n");
    uint16_t failedAssertions = 0;

    uint8_t topicName[] = "TOPIC";
    uint8_t payload[] = { 0x00, 0x01, 0x02 };

    struct MqttPublishPacket packet = {
        .packetIdentifier = 0xAABB,
        .dup = 1,
        .qos = MQTT_QOS_EXACTLY_ONCE,
        .retain = 1,
        .topicName = topicName,
        .topicNameSize = 5,
        .payload = payload,
        .payloadSize = 3,
    };

    uint8_t bytes[14];
    uint32_t size = packMqttPublish(bytes, &packet);

    if (size != 14)
    {
        printf("Expected size to be 14 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x3D)
    {
        printf("Expected byte[0] to be 0x3D but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 12)
    {
        printf("Expected byte[1] to be 12 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Topic name - Length MSB
    if (bytes[2] != 0x00)
    {
        printf("Expected byte[2] to be 0x00 but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Topic name - Length LSB
    if (bytes[3] != 0x05)
    {
        printf("Expected byte[3] to be 0x05 but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    // Variable header - Topic name - T
    if (bytes[4] != 0x54)
    {
        printf("Expected byte[4] to be 0x54 but was 0x%X\n", bytes[4]);
        failedAssertions++;
    }

    // Variable header - Topic name - O
    if (bytes[5] != 0x4F)
    {
        printf("Expected byte[5] to be 0x4F but was 0x%X\n", bytes[5]);
        failedAssertions++;
    }

    // Variable header - Topic name - P
    if (bytes[6] != 0x50)
    {
        printf("Expected byte[6] to be 0x50 but was 0x%X\n", bytes[6]);
        failedAssertions++;
    }

    // Variable header - Topic name - I
    if (bytes[7] != 0x49)
    {
        printf("Expected byte[7] to be 0x49 but was 0x%X\n", bytes[7]);
        failedAssertions++;
    }

    // Variable header - Topic name - C
    if (bytes[8] != 0x43)
    {
        printf("Expected byte[8] to be 0x43 but was 0x%X\n", bytes[8]);
        failedAssertions++;
    }

    // Variable header - Packet identifier MSB
    if (bytes[9] != 0xAA)
    {
        printf("Expected byte[9] to be 0xAA but was 0x%X\n", bytes[9]);
        failedAssertions++;
    }

    // Variable header - Packet identifier LSB
    if (bytes[10] != 0xBB)
    {
        printf("Expected byte[10] to be 0xBB but was 0x%X\n", bytes[10]);
        failedAssertions++;
    }

    // Payload - Byte 1
    if (bytes[11] != 0x00)
    {
        printf("Expected byte[11] to be 0x00 but was 0x%X\n", bytes[11]);
        failedAssertions++;
    }

    // Payload - Byte 2
    if (bytes[12] != 0x01)
    {
        printf("Expected byte[12] to be 0x01 but was 0x%X\n", bytes[12]);
        failedAssertions++;
    }

    // Payload - Byte 3
    if (bytes[13] != 0x02)
    {
        printf("Expected byte[13] to be 0x02 but was 0x%X\n", bytes[13]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackPubAck()
{
    printf("It should pack PUBACK\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[4];
    uint32_t size = packMqttPubAck(bytes, 0xAABB);

    if (size != 4)
    {
        printf("Expected size to be 4 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x40)
    {
        printf("Expected byte[0] to be 0x40 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 2)
    {
        printf("Expected byte[1] to be 2 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length MSB
    if (bytes[2] != 0xAA)
    {
        printf("Expected byte[2] to be 0xAA but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length LSB
    if (bytes[3] != 0xBB)
    {
        printf("Expected byte[3] to be 0xBB but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackPubRec()
{
    printf("It should pack PUBREC\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[4];
    uint32_t size = packMqttPubRec(bytes, 0xAABB);

    if (size != 4)
    {
        printf("Expected size to be 4 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x50)
    {
        printf("Expected byte[0] to be 0x50 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 2)
    {
        printf("Expected byte[1] to be 2 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length MSB
    if (bytes[2] != 0xAA)
    {
        printf("Expected byte[2] to be 0xAA but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length LSB
    if (bytes[3] != 0xBB)
    {
        printf("Expected byte[3] to be 0xBB but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackPubRel()
{
    printf("It should pack PUBREL\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[4];
    uint32_t size = packMqttPubRel(bytes, 0xAABB);

    if (size != 4)
    {
        printf("Expected size to be 4 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x62)
    {
        printf("Expected byte[0] to be 0x62 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 2)
    {
        printf("Expected byte[1] to be 2 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length MSB
    if (bytes[2] != 0xAA)
    {
        printf("Expected byte[2] to be 0xAA but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length LSB
    if (bytes[3] != 0xBB)
    {
        printf("Expected byte[3] to be 0xBB but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackPubComp()
{
    printf("It should pack PUBCOMP\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[4];
    uint32_t size = packMqttPubComp(bytes, 0xAABB);

    if (size != 4)
    {
        printf("Expected size to be 4 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x70)
    {
        printf("Expected byte[0] to be 0x70 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 2)
    {
        printf("Expected byte[1] to be 2 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length MSB
    if (bytes[2] != 0xAA)
    {
        printf("Expected byte[2] to be 0xAA but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length LSB
    if (bytes[3] != 0xBB)
    {
        printf("Expected byte[3] to be 0xBB but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackSubscribe()
{
    printf("It should pack SUBSCRIBE\n");
    uint16_t failedAssertions = 0;

    uint8_t topicFilter[] = "TOPIC";

    struct MqttUnSubscribePacket packet = {
        .packetIdentifier = 0xAABB,
        .topicFilter = topicFilter,
        .topicFilterSize = 5,
        .qos = MQTT_QOS_EXACTLY_ONCE
    };

    uint8_t bytes[12];
    uint32_t size = packMqttSubscribe(bytes, &packet);

    if (size != 12)
    {
        printf("Expected size to be 12 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0x82)
    {
        printf("Expected byte[0] to be 0x82 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 10)
    {
        printf("Expected byte[1] to be 10 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length MSB
    if (bytes[2] != 0xAA)
    {
        printf("Expected byte[2] to be 0xAA but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length LSB
    if (bytes[3] != 0xBB)
    {
        printf("Expected byte[3] to be 0xBB but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    // Payload - Topic filter - Length MSB
    if (bytes[4] != 0x00)
    {
        printf("Expected byte[4] to be 0x00 but was 0x%X\n", bytes[4]);
        failedAssertions++;
    }

    // Payload - Topic filter - Length LSB
    if (bytes[5] != 0x05)
    {
        printf("Expected byte[5] to be 0x05 but was 0x%X\n", bytes[5]);
        failedAssertions++;
    }

    // Payload - Topic filter - T
    if (bytes[6] != 0x54)
    {
        printf("Expected byte[6] to be 0x54 but was 0x%X\n", bytes[6]);
        failedAssertions++;
    }

    // Payload - Topic filter - O
    if (bytes[7] != 0x4F)
    {
        printf("Expected byte[7] to be 0x4F but was 0x%X\n", bytes[7]);
        failedAssertions++;
    }

    // Payload - Topic filter - P
    if (bytes[8] != 0x50)
    {
        printf("Expected byte[8] to be 0x50 but was 0x%X\n", bytes[8]);
        failedAssertions++;
    }

    // Payload - Topic filter - I
    if (bytes[9] != 0x49)
    {
        printf("Expected byte[9] to be 0x49 but was 0x%X\n", bytes[9]);
        failedAssertions++;
    }

    // Payload - Topic filter - C
    if (bytes[10] != 0x43)
    {
        printf("Expected byte[10] to be 0x43 but was 0x%X\n", bytes[10]);
        failedAssertions++;
    }

    // Payload - QoS
    if (bytes[11] != 0x02)
    {
        printf("Expected byte[11] to be 0x02 but was 0x%X\n", bytes[11]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackUnsubscribe()
{
    printf("It should pack UBSUBSCRIBE\n");
    uint16_t failedAssertions = 0;

    uint8_t topicFilter[] = "TOPIC";

    struct MqttUnSubscribePacket packet = {
        .packetIdentifier = 0xAABB,
        .topicFilter = topicFilter,
        .topicFilterSize = 5,
        .qos = MQTT_QOS_EXACTLY_ONCE
    };

    uint8_t bytes[11];
    uint32_t size = packMqttUnsubscribe(bytes, &packet);

    if (size != 11)
    {
        printf("Expected size to be 11 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0xA2)
    {
        printf("Expected byte[0] to be 0xA2 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 9)
    {
        printf("Expected byte[1] to be 9 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length MSB
    if (bytes[2] != 0xAA)
    {
        printf("Expected byte[2] to be 0xAA but was 0x%X\n", bytes[2]);
        failedAssertions++;
    }

    // Variable header - Packet identifier - Length LSB
    if (bytes[3] != 0xBB)
    {
        printf("Expected byte[3] to be 0xBB but was 0x%X\n", bytes[3]);
        failedAssertions++;
    }

    // Payload - Topic filter - Length MSB
    if (bytes[4] != 0x00)
    {
        printf("Expected byte[4] to be 0x00 but was 0x%X\n", bytes[4]);
        failedAssertions++;
    }

    // Payload - Topic filter - Length LSB
    if (bytes[5] != 0x05)
    {
        printf("Expected byte[5] to be 0x05 but was 0x%X\n", bytes[5]);
        failedAssertions++;
    }

    // Payload - Topic filter - T
    if (bytes[6] != 0x54)
    {
        printf("Expected byte[6] to be 0x54 but was 0x%X\n", bytes[6]);
        failedAssertions++;
    }

    // Payload - Topic filter - O
    if (bytes[7] != 0x4F)
    {
        printf("Expected byte[7] to be 0x4F but was 0x%X\n", bytes[7]);
        failedAssertions++;
    }

    // Payload - Topic filter - P
    if (bytes[8] != 0x50)
    {
        printf("Expected byte[8] to be 0x50 but was 0x%X\n", bytes[8]);
        failedAssertions++;
    }

    // Payload - Topic filter - I
    if (bytes[9] != 0x49)
    {
        printf("Expected byte[9] to be 0x49 but was 0x%X\n", bytes[9]);
        failedAssertions++;
    }

    // Payload - Topic filter - C
    if (bytes[10] != 0x43)
    {
        printf("Expected byte[10] to be 0x43 but was 0x%X\n", bytes[10]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackPingReq()
{
    printf("It should pack PINGREQ\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[2];
    uint32_t size = packMqttPingReq(bytes);

    if (size != 2)
    {
        printf("Expected size to be 2 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0xC0)
    {
        printf("Expected byte[0] to be 0xC0 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 0)
    {
        printf("Expected byte[1] to be 0 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}

static uint16_t itShouldPackDisconnect()
{
    printf("It should pack DISCONNECT\n");
    uint16_t failedAssertions = 0;

    uint8_t bytes[2];
    uint32_t size = packMqttDisconnect(bytes);

    if (size != 2)
    {
        printf("Expected size to be 2 but was %i\n", size);
        failedAssertions++;
    }

    // Fixed header - Packet type
    if (bytes[0] != 0xE0)
    {
        printf("Expected byte[0] to be 0xE0 but was 0x%X\n", bytes[0]);
        failedAssertions++;
    }

    // Fixed header - Remaining length
    if (bytes[1] != 0)
    {
        printf("Expected byte[1] to be 0 but was %i\n", bytes[1]);
        failedAssertions++;
    }

    printf("Failed assertions: %i\n\n", failedAssertions);
    return failedAssertions;
}
