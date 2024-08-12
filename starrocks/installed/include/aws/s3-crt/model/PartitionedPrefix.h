﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/s3-crt/model/PartitionDateSource.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace S3Crt
{
namespace Model
{

  /**
   * <p>Amazon S3 keys for log objects are partitioned in the following format:</p>
   * <p>
   * <code>[DestinationPrefix][SourceAccountId]/[SourceRegion]/[SourceBucket]/[YYYY]/[MM]/[DD]/[YYYY]-[MM]-[DD]-[hh]-[mm]-[ss]-[UniqueString]</code>
   * </p> <p>PartitionedPrefix defaults to EventTime delivery when server access logs
   * are delivered.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/PartitionedPrefix">AWS
   * API Reference</a></p>
   */
  class PartitionedPrefix
  {
  public:
    AWS_S3CRT_API PartitionedPrefix();
    AWS_S3CRT_API PartitionedPrefix(const Aws::Utils::Xml::XmlNode& xmlNode);
    AWS_S3CRT_API PartitionedPrefix& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    AWS_S3CRT_API void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    /**
     * <p>Specifies the partition date source for the partitioned prefix.
     * PartitionDateSource can be EventTime or DeliveryTime.</p>
     */
    inline const PartitionDateSource& GetPartitionDateSource() const{ return m_partitionDateSource; }

    /**
     * <p>Specifies the partition date source for the partitioned prefix.
     * PartitionDateSource can be EventTime or DeliveryTime.</p>
     */
    inline bool PartitionDateSourceHasBeenSet() const { return m_partitionDateSourceHasBeenSet; }

    /**
     * <p>Specifies the partition date source for the partitioned prefix.
     * PartitionDateSource can be EventTime or DeliveryTime.</p>
     */
    inline void SetPartitionDateSource(const PartitionDateSource& value) { m_partitionDateSourceHasBeenSet = true; m_partitionDateSource = value; }

    /**
     * <p>Specifies the partition date source for the partitioned prefix.
     * PartitionDateSource can be EventTime or DeliveryTime.</p>
     */
    inline void SetPartitionDateSource(PartitionDateSource&& value) { m_partitionDateSourceHasBeenSet = true; m_partitionDateSource = std::move(value); }

    /**
     * <p>Specifies the partition date source for the partitioned prefix.
     * PartitionDateSource can be EventTime or DeliveryTime.</p>
     */
    inline PartitionedPrefix& WithPartitionDateSource(const PartitionDateSource& value) { SetPartitionDateSource(value); return *this;}

    /**
     * <p>Specifies the partition date source for the partitioned prefix.
     * PartitionDateSource can be EventTime or DeliveryTime.</p>
     */
    inline PartitionedPrefix& WithPartitionDateSource(PartitionDateSource&& value) { SetPartitionDateSource(std::move(value)); return *this;}

  private:

    PartitionDateSource m_partitionDateSource;
    bool m_partitionDateSourceHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
