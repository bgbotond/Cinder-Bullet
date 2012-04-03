/*
* CinderBullet originally created by Peter Holzkorn on 2/16/10
* 
* Copyright (c) 2012, Ban the Rewind
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or 
* without modification, are permitted provided that the following 
* conditions are met:
* 
* Redistributions of source code must retain the above copyright 
* notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright 
* notice, this list of conditions and the following disclaimer in 
* the documentation and/or other materials provided with the 
* distribution.
* 
* Neither the name of the Ban the Rewind nor the names of its 
* contributors may be used to endorse or promote products 
* derived from this software without specific prior written 
* permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#pragma once

// Includes
#include "CollisionObject.h"
#include "DynamicsWorld.h"
#include "Utilities.h"

namespace bullet
{

	class RigidBox : public CollisionObject 
	{
	private:
		RigidBox( const ci::Vec3f &dimensions, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		friend CollisionObjectRef	createRigidBox( const DynamicsWorldRef &world, const ci::Vec3f &dimensions, float mass, 
													const ci::Vec3f &position, const ci::Quatf &rotation );
	};

	class RigidCylinder : public CollisionObject 
	{
	private:
		RigidCylinder( float topRadius, float bottomRadius, float height, int32_t segments, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		friend CollisionObjectRef	createRigidCylinder( const DynamicsWorldRef &world, float topRadius, float bottomRadius, 
														float height, int32_t segments, float mass, const ci::Vec3f &position, 
														const ci::Quatf &rotation );
	};

	class RigidHull : public CollisionObject 
	{
	private:
		RigidHull( const ci::TriMesh &mesh, const ci::Vec3f &scale, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		friend CollisionObjectRef	createRigidHull( const DynamicsWorldRef &world, const ci::TriMesh &mesh, const ci::Vec3f &scale, 
													float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
	};

	class RigidMesh : public CollisionObject 
	{
	private:
		RigidMesh( const ci::TriMesh &mesh, const ci::Vec3f &scale, float margin, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		friend CollisionObjectRef	createRigidMesh( const DynamicsWorldRef &world, const ci::TriMesh &mesh, const ci::Vec3f &scale, 
													float margin, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
	};

	class RigidSphere : public CollisionObject 
	{
	private:
		RigidSphere( float radius, int32_t segments, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		friend CollisionObjectRef	createRigidSphere( const DynamicsWorldRef &world, float radius, int32_t segments, float mass, 
														const ci::Vec3f &position, const ci::Quatf &rotation );
	};

	class RigidTerrain : public CollisionObject 
	{
	private:
		RigidTerrain( const ci::Surface32f &heightField, int32_t stickWidth, int32_t stickLength, float minHeight, float maxHeight, 
			int32_t upAxis, const ci::Vec3f &scale, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		friend CollisionObjectRef	createRigidTerrain( const DynamicsWorldRef &world, const ci::Surface32f &heightField, 
														int32_t stickWidth, int32_t stickLength, float minHeight, float maxHeight, 
														int32_t upAxis, const ci::Vec3f &scale, float mass, const ci::Vec3f &position, 
														const ci::Quatf &rotation );
	};

	class RigidBody
	{
	private:
		static btRigidBody*	create( btCollisionShape* shape, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		static btRigidBody*	createBox( const ci::Vec3f &size, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		static btRigidBody*	createCylinder( float topRadius, float bottomRadius, float height, int32_t segments, 
			float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		static btRigidBody*	createHull( btConvexHullShape* shape, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		static btRigidBody*	createMesh( btBvhTriangleMeshShape* shape, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		static btRigidBody*	createSphere( float radius, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		static btRigidBody*	createTerrain( btHeightfieldTerrainShape* shape, float mass, const ci::Vec3f &position, const ci::Quatf &rotation );
		
		friend class		RigidBox;
		friend class		RigidCylinder;
		friend class		RigidHull;
		friend class		RigidMesh;
		friend class		RigidSphere;
		friend class		RigidTerrain;
	};

}
