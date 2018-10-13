#include "record.h"
#include "testrecord.h"
#include <vector>


RecordTest::RecordTest()
{
};

RecordTest::~RecordTest()
{
};

void RecordTest::SetUp()
{
};

void RecordTest::TearDown()
{
};

TEST_F(RecordTest, ProtocolVersionSizeAligned)
{
    tls::ProtocolVersion version;
    version.major = 0x1;
    version.minor = 0x2;
    ASSERT_EQ(sizeof(version), sizeof(version.major) + sizeof(version.minor));
    ASSERT_EQ(sizeof(tls::ProtocolVersion), 2);
}

TEST_F(RecordTest, TlsPlaintextZeroFragmentSizeAligned)
{   
    size_t expSize = 0;
    expSize += sizeof(tls::TlsPlaintext::type);
    expSize += sizeof(tls::TlsPlaintext::version);
    expSize += sizeof(tls::TlsPlaintext::length);
    expSize += sizeof(tls::TlsPlaintext::fragment);

    ASSERT_EQ(expSize, sizeof(tls::TlsPlaintext));
}

TEST_F(RecordTest, TlsPlaintextFragmentSizeAligned)
{
    // allocate a buffer to hold the packet
    // we want say 8 bytes of packet fragment
    uint16_t length = 8;
    size_t expSize = sizeof(tls::TlsPlaintext);
    expSize += (length * sizeof(uint8_t));

    std::vector<uint8_t> buf(expSize, 0);
    tls::TlsPlaintext *pTlsRecord = 
        reinterpret_cast<tls::TlsPlaintext*>(buf.data());
        pTlsRecord->length = length;
    
        for(int i = 0; i < length; ++i)
        {
            ASSERT_NO_THROW(pTlsRecord->fragment[i] = static_cast<uint8_t>(1));
        }
}