/* SPDX-FileCopyrightText: 2024 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#include "gpu_shader_create_info.hh"

GPU_SHADER_CREATE_INFO(compositor_scale_variable)
LOCAL_GROUP_SIZE(16, 16)
SAMPLER(0, FLOAT_2D, input_tx)
SAMPLER(1, FLOAT_2D, x_scale_tx)
SAMPLER(2, FLOAT_2D, y_scale_tx)
IMAGE(0, GPU_RGBA16F, WRITE, FLOAT_2D, output_img)
COMPUTE_SOURCE("compositor_scale_variable.glsl")
GPU_SHADER_CREATE_END()

GPU_SHADER_CREATE_INFO(compositor_scale_variable_shared)
ADDITIONAL_INFO(compositor_scale_variable)
DEFINE_VALUE("SAMPLER_FUNCTION", "texture")
GPU_SHADER_CREATE_END()

GPU_SHADER_CREATE_INFO(compositor_scale_variable_float)
ADDITIONAL_INFO(compositor_scale_variable_shared)
IMAGE(0, GPU_R16F, WRITE, FLOAT_2D, output_img)
DO_STATIC_COMPILATION()
GPU_SHADER_CREATE_END()

GPU_SHADER_CREATE_INFO(compositor_scale_variable_float4)
ADDITIONAL_INFO(compositor_scale_variable_shared)
IMAGE(0, GPU_RGBA16F, WRITE, FLOAT_2D, output_img)
DO_STATIC_COMPILATION()
GPU_SHADER_CREATE_END()

GPU_SHADER_CREATE_INFO(compositor_scale_variable_bicubic_shared)
ADDITIONAL_INFO(compositor_scale_variable_shared)
DEFINE_VALUE("SAMPLER_FUNCTION", "texture_bicubic")
GPU_SHADER_CREATE_END()

GPU_SHADER_CREATE_INFO(compositor_scale_variable_bicubic_float)
ADDITIONAL_INFO(compositor_scale_variable_bicubic_shared)
IMAGE(0, GPU_R16F, WRITE, FLOAT_2D, output_img)
DO_STATIC_COMPILATION()
GPU_SHADER_CREATE_END()

GPU_SHADER_CREATE_INFO(compositor_scale_variable_bicubic_float4)
ADDITIONAL_INFO(compositor_scale_variable_bicubic_shared)
IMAGE(0, GPU_RGBA16F, WRITE, FLOAT_2D, output_img)
DO_STATIC_COMPILATION()
GPU_SHADER_CREATE_END()
