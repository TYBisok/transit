﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/utils/event/EventStreamHandler.h>
#include <aws/core/client/AWSError.h>
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/s3-crt/S3CrtErrors.h>

#include <aws/s3-crt/model/SelectObjectContentInitialResponse.h>
#include <aws/s3-crt/model/RecordsEvent.h>
#include <aws/s3-crt/model/StatsEvent.h>
#include <aws/s3-crt/model/ProgressEvent.h>

namespace Aws
{
namespace S3Crt
{
namespace Model
{
    enum class SelectObjectContentEventType
    {
        INITIAL_RESPONSE,
        RECORDS,
        STATS,
        PROGRESS,
        CONT,
        END,
        UNKNOWN
    };

    class SelectObjectContentHandler : public Aws::Utils::Event::EventStreamHandler
    {
        typedef std::function<void(const SelectObjectContentInitialResponse&)> SelectObjectContentInitialResponseCallback;
        typedef std::function<void(const RecordsEvent&)> RecordsEventCallback;
        typedef std::function<void(const StatsEvent&)> StatsEventCallback;
        typedef std::function<void(const ProgressEvent&)> ProgressEventCallback;
        typedef std::function<void()> ContinuationEventCallback;
        typedef std::function<void()> EndEventCallback;
        typedef std::function<void(const Aws::Client::AWSError<S3CrtErrors>& error)> ErrorCallback;

    public:
        AWS_S3CRT_API SelectObjectContentHandler();
        AWS_S3CRT_API SelectObjectContentHandler& operator=(const SelectObjectContentHandler&) = default;

        AWS_S3CRT_API virtual void OnEvent() override;

        inline void SetInitialResponseCallback(const SelectObjectContentInitialResponseCallback& callback) { m_onInitialResponse = callback; }
        inline void SetRecordsEventCallback(const RecordsEventCallback& callback) { m_onRecordsEvent = callback; }
        inline void SetStatsEventCallback(const StatsEventCallback& callback) { m_onStatsEvent = callback; }
        inline void SetProgressEventCallback(const ProgressEventCallback& callback) { m_onProgressEvent = callback; }
        inline void SetContinuationEventCallback(const ContinuationEventCallback& callback) { m_onContinuationEvent = callback; }
        inline void SetEndEventCallback(const EndEventCallback& callback) { m_onEndEvent = callback; }
        inline void SetOnErrorCallback(const ErrorCallback& callback) { m_onError = callback; }

    private:
        AWS_S3CRT_API void HandleEventInMessage();
        AWS_S3CRT_API void HandleErrorInMessage();
        AWS_S3CRT_API void MarshallError(const Aws::String& errorCode, const Aws::String& errorMessage);

        SelectObjectContentInitialResponseCallback m_onInitialResponse;
        RecordsEventCallback m_onRecordsEvent;
        StatsEventCallback m_onStatsEvent;
        ProgressEventCallback m_onProgressEvent;
        ContinuationEventCallback m_onContinuationEvent;
        EndEventCallback m_onEndEvent;
        ErrorCallback m_onError;
    };

namespace SelectObjectContentEventMapper
{
    AWS_S3CRT_API SelectObjectContentEventType GetSelectObjectContentEventTypeForName(const Aws::String& name);

    AWS_S3CRT_API Aws::String GetNameForSelectObjectContentEventType(SelectObjectContentEventType value);
} // namespace SelectObjectContentEventMapper
} // namespace Model
} // namespace S3Crt
} // namespace Aws
