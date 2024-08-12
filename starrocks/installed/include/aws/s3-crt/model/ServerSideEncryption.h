﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace S3Crt
{
namespace Model
{
  enum class ServerSideEncryption
  {
    NOT_SET,
    AES256,
    aws_kms,
    aws_kms_dsse
  };

namespace ServerSideEncryptionMapper
{
AWS_S3CRT_API ServerSideEncryption GetServerSideEncryptionForName(const Aws::String& name);

AWS_S3CRT_API Aws::String GetNameForServerSideEncryption(ServerSideEncryption value);
} // namespace ServerSideEncryptionMapper
} // namespace Model
} // namespace S3Crt
} // namespace Aws
