﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/s3-crt/model/TransitionStorageClass.h>
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
   * <p>Container for the transition rule that describes when noncurrent objects
   * transition to the <code>STANDARD_IA</code>, <code>ONEZONE_IA</code>,
   * <code>INTELLIGENT_TIERING</code>, <code>GLACIER_IR</code>, <code>GLACIER</code>,
   * or <code>DEEP_ARCHIVE</code> storage class. If your bucket is versioning-enabled
   * (or versioning is suspended), you can set this action to request that Amazon S3
   * transition noncurrent object versions to the <code>STANDARD_IA</code>,
   * <code>ONEZONE_IA</code>, <code>INTELLIGENT_TIERING</code>,
   * <code>GLACIER_IR</code>, <code>GLACIER</code>, or <code>DEEP_ARCHIVE</code>
   * storage class at a specific period in the object's lifetime.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/NoncurrentVersionTransition">AWS
   * API Reference</a></p>
   */
  class NoncurrentVersionTransition
  {
  public:
    AWS_S3CRT_API NoncurrentVersionTransition();
    AWS_S3CRT_API NoncurrentVersionTransition(const Aws::Utils::Xml::XmlNode& xmlNode);
    AWS_S3CRT_API NoncurrentVersionTransition& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    AWS_S3CRT_API void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    /**
     * <p>Specifies the number of days an object is noncurrent before Amazon S3 can
     * perform the associated action. For information about the noncurrent days
     * calculations, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How
     * Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon
     * S3 User Guide</i>.</p>
     */
    inline int GetNoncurrentDays() const{ return m_noncurrentDays; }

    /**
     * <p>Specifies the number of days an object is noncurrent before Amazon S3 can
     * perform the associated action. For information about the noncurrent days
     * calculations, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How
     * Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon
     * S3 User Guide</i>.</p>
     */
    inline bool NoncurrentDaysHasBeenSet() const { return m_noncurrentDaysHasBeenSet; }

    /**
     * <p>Specifies the number of days an object is noncurrent before Amazon S3 can
     * perform the associated action. For information about the noncurrent days
     * calculations, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How
     * Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon
     * S3 User Guide</i>.</p>
     */
    inline void SetNoncurrentDays(int value) { m_noncurrentDaysHasBeenSet = true; m_noncurrentDays = value; }

    /**
     * <p>Specifies the number of days an object is noncurrent before Amazon S3 can
     * perform the associated action. For information about the noncurrent days
     * calculations, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#non-current-days-calculations">How
     * Amazon S3 Calculates How Long an Object Has Been Noncurrent</a> in the <i>Amazon
     * S3 User Guide</i>.</p>
     */
    inline NoncurrentVersionTransition& WithNoncurrentDays(int value) { SetNoncurrentDays(value); return *this;}


    /**
     * <p>The class of storage used to store the object.</p>
     */
    inline const TransitionStorageClass& GetStorageClass() const{ return m_storageClass; }

    /**
     * <p>The class of storage used to store the object.</p>
     */
    inline bool StorageClassHasBeenSet() const { return m_storageClassHasBeenSet; }

    /**
     * <p>The class of storage used to store the object.</p>
     */
    inline void SetStorageClass(const TransitionStorageClass& value) { m_storageClassHasBeenSet = true; m_storageClass = value; }

    /**
     * <p>The class of storage used to store the object.</p>
     */
    inline void SetStorageClass(TransitionStorageClass&& value) { m_storageClassHasBeenSet = true; m_storageClass = std::move(value); }

    /**
     * <p>The class of storage used to store the object.</p>
     */
    inline NoncurrentVersionTransition& WithStorageClass(const TransitionStorageClass& value) { SetStorageClass(value); return *this;}

    /**
     * <p>The class of storage used to store the object.</p>
     */
    inline NoncurrentVersionTransition& WithStorageClass(TransitionStorageClass&& value) { SetStorageClass(std::move(value)); return *this;}


    /**
     * <p>Specifies how many newer noncurrent versions must exist before Amazon S3 can
     * perform the associated action on a given version. If there are this many more
     * recent noncurrent versions, Amazon S3 will take the associated action. For more
     * information about noncurrent versions, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intro-lifecycle-rules.html">Lifecycle
     * configuration elements</a> in the <i>Amazon S3 User Guide</i>.</p>
     */
    inline int GetNewerNoncurrentVersions() const{ return m_newerNoncurrentVersions; }

    /**
     * <p>Specifies how many newer noncurrent versions must exist before Amazon S3 can
     * perform the associated action on a given version. If there are this many more
     * recent noncurrent versions, Amazon S3 will take the associated action. For more
     * information about noncurrent versions, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intro-lifecycle-rules.html">Lifecycle
     * configuration elements</a> in the <i>Amazon S3 User Guide</i>.</p>
     */
    inline bool NewerNoncurrentVersionsHasBeenSet() const { return m_newerNoncurrentVersionsHasBeenSet; }

    /**
     * <p>Specifies how many newer noncurrent versions must exist before Amazon S3 can
     * perform the associated action on a given version. If there are this many more
     * recent noncurrent versions, Amazon S3 will take the associated action. For more
     * information about noncurrent versions, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intro-lifecycle-rules.html">Lifecycle
     * configuration elements</a> in the <i>Amazon S3 User Guide</i>.</p>
     */
    inline void SetNewerNoncurrentVersions(int value) { m_newerNoncurrentVersionsHasBeenSet = true; m_newerNoncurrentVersions = value; }

    /**
     * <p>Specifies how many newer noncurrent versions must exist before Amazon S3 can
     * perform the associated action on a given version. If there are this many more
     * recent noncurrent versions, Amazon S3 will take the associated action. For more
     * information about noncurrent versions, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intro-lifecycle-rules.html">Lifecycle
     * configuration elements</a> in the <i>Amazon S3 User Guide</i>.</p>
     */
    inline NoncurrentVersionTransition& WithNewerNoncurrentVersions(int value) { SetNewerNoncurrentVersions(value); return *this;}

  private:

    int m_noncurrentDays;
    bool m_noncurrentDaysHasBeenSet = false;

    TransitionStorageClass m_storageClass;
    bool m_storageClassHasBeenSet = false;

    int m_newerNoncurrentVersions;
    bool m_newerNoncurrentVersionsHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
