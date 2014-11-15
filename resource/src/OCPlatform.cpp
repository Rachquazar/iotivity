//******************************************************************
//
// Copyright 2014 Intel Mobile Communications GmbH All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//******************************************************************
// File name:
//     OCPlatform.cpp
//
// Description: Implementation of the OCPlatform.
//
//
//
//*********************************************************************
#include <OCPlatform.h>
namespace OC
{
    namespace OCPlatform
    {
        void Configure(const PlatformConfig& config)
        {
            OCPlatform_impl::Configure(config);
        }

        OCStackResult setDefaultDeviceEntityHandler(EntityHandler entityHandler)
        {
            return OCPlatform_impl::Instance().setDefaultDeviceEntityHandler(entityHandler);
        }

        OCStackResult notifyAllObservers(OCResourceHandle resourceHandle,
                                                QualityOfService QoS)
        {
            return OCPlatform_impl::Instance().notifyAllObservers(resourceHandle, QoS);
        }

        OCStackResult notifyAllObservers(OCResourceHandle resourceHandle)
        {
            return OCPlatform_impl::Instance().notifyAllObservers(resourceHandle);
        }

        OCStackResult notifyListOfObservers(OCResourceHandle resourceHandle,
                                                ObservationIds& observationIds,
                                                const std::shared_ptr<OCResourceResponse> pResponse)
        {
            return OCPlatform_impl::Instance().notifyListOfObservers(resourceHandle,
                                                observationIds, pResponse);
        }

        OCStackResult notifyListOfObservers(OCResourceHandle resourceHandle,
                                                ObservationIds& observationIds,
                                                const std::shared_ptr<OCResourceResponse> pResponse,
                                                QualityOfService QoS)
        {
            return OCPlatform_impl::Instance().notifyListOfObservers(resourceHandle,
                                                    observationIds, pResponse, QoS);
        }

        OCResource::Ptr constructResourceObject(const std::string& host,
                                                const std::string& uri,
                                                bool isObservable,
                                                const std::vector<std::string>& resourceTypes,
                                                const std::vector<std::string>& interfaces)
        {
            return OCPlatform_impl::Instance().constructResourceObject(host, uri, isObservable,
                                                resourceTypes, interfaces);
        }

        OCStackResult findResource(const std::string& host,
                                                const std::string& resourceName,
                                                FindCallback resourceHandler)
        {
            return OCPlatform_impl::Instance().findResource(host, resourceName, resourceHandler);
        }

        OCStackResult findResource(const std::string& host,
                                                const std::string& resourceName,
                                                FindCallback resourceHandler, QualityOfService QoS)
        {
            return OCPlatform_impl::Instance().findResource(host, resourceName,
                                                resourceHandler, QoS);
        }


        OCStackResult registerResource(OCResourceHandle& resourceHandle,
                                                std::string& resourceURI,
                                                const std::string& resourceTypeName,
                                                const std::string& resourceInterface,
                                                EntityHandler entityHandler,
                                                uint8_t resourceProperty)
        {
            return OCPlatform_impl::Instance().registerResource(resourceHandle, resourceURI,
                                                resourceTypeName, resourceInterface,
                                                entityHandler, resourceProperty);
        }

        OCStackResult registerResource(OCResourceHandle& resourceHandle,
                                                const std::shared_ptr< OCResource > resource)
        {
            return OCPlatform_impl::Instance().registerResource(resourceHandle, resource);
        }

        OCStackResult unregisterResource(const OCResourceHandle& resourceHandle)
        {
            return OCPlatform_impl::Instance().unregisterResource(resourceHandle);
        }

        OCStackResult unbindResource(OCResourceHandle collectionHandle,
                                                OCResourceHandle resourceHandle)
        {
            return OCPlatform_impl::Instance().unbindResource(collectionHandle, resourceHandle);
        }

        OCStackResult unbindResources(const OCResourceHandle collectionHandle,
                                                const std::vector<OCResourceHandle>& resourceHandles
                                                )
        {
            return OCPlatform_impl::Instance().unbindResources(collectionHandle, resourceHandles);
        }

        OCStackResult bindResource(const OCResourceHandle collectionHandle,
                                                const OCResourceHandle resourceHandle)
        {
            return OCPlatform_impl::Instance().bindResource(collectionHandle, resourceHandle);
        }

        OCStackResult bindResources(const OCResourceHandle collectionHandle,
                                                const std::vector<OCResourceHandle>& resourceHandles
                                                )
        {
            return OCPlatform_impl::Instance().bindResources(collectionHandle, resourceHandles);
        }

        OCStackResult bindTypeToResource(const OCResourceHandle& resourceHandle,
                                                const std::string& resourceTypeName)
        {
            return OCPlatform_impl::Instance().bindTypeToResource(resourceHandle,resourceTypeName);
        }

        OCStackResult bindInterfaceToResource(const OCResourceHandle& resourceHandle,
                                                const std::string& resourceInterfaceName)
        {
            return OCPlatform_impl::Instance().bindInterfaceToResource(resourceHandle,
                                                resourceInterfaceName);
        }

        OCStackResult startPresence(const unsigned int announceDurationSeconds)
        {
            return OCPlatform_impl::Instance().startPresence(announceDurationSeconds);
        }

        OCStackResult stopPresence()
        {
            return OCPlatform_impl::Instance().stopPresence();
        }

        OCStackResult subscribePresence(OCPresenceHandle& presenceHandle,
                                                const std::string& host,
                                                SubscribeCallback presenceHandler)
        {
            return OCPlatform_impl::Instance().subscribePresence(presenceHandle, host,
                                                presenceHandler);
        }

        OCStackResult subscribePresence(OCPresenceHandle& presenceHandle,
                                                const std::string& host,
                                                const std::string& resourceType,
                                                SubscribeCallback presenceHandler)
        {
            return OCPlatform_impl::Instance().subscribePresence(presenceHandle, host,
                                                resourceType, presenceHandler);
        }

        OCStackResult unsubscribePresence(OCPresenceHandle presenceHandle)
        {
            return OCPlatform_impl::Instance().unsubscribePresence(presenceHandle);
        }
    } // namespace OCPlatform
} //namespace OC
