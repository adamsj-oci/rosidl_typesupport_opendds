#ifndef ROSIDL_TYPESUPPORT_OPENDDS_CPP__REQUESTER_H_
#define ROSIDL_TYPESUPPORT_OPENDDS_CPP__REQUESTER_H_

namespace rosidl_typesupport_opendds_cpp
{

  template <typename TRequest, typename TReply>
  class Requester {
  public:
    typedef typename OpenDDS::DCPS::DDSTraits<TRequest>::DataWriterType RequestDataWriter;
    typedef typename OpenDDS::DCPS::DDSTraits<TReply>::DataReaderType ReplyDataReader;

    typedef RequesterParams Params;

    // TODO: remove unused commented out lines
    //typedef typename details::vendor_dependent<Requester<TRequest, TReply>>::type VendorDependent;

    //typedef TRequest RequestType;
    //typedef TReply ReplyType;

    Requester();

    explicit Requester(const RequesterParams& params);

    //Requester(const Requester&);

    //void swap(Requester& other);

    //Requester& operator = (const Requester&);

    RequesterParams get_requester_params() const;

    DDS::DataWriter* get_request_datawriter() const;

    DDS::DataReader* get_reply_datareader() const;

    OpenDDS::RTPS::SequenceNumber_t get_sequence_number() const;

    DDS::ReturnCode_t send_request(const TRequest&);

    DDS::ReturnCode_t take_reply(TReply& reply);

    virtual ~Requester();

  private:
    RequesterParams* requester_params;

    OpenDDS::RTPS::SequenceNumber_t sequence_number;

    RequestDataWriter* request_datawriter;

    ReplyDataReader* reply_datareader;

    OpenDDS::DCPS::DataWriterImpl* dw_impl;

    OpenDDS::DCPS::RepoId pub_id;

  };

}

#endif
