/* ****************************************************************
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/
#ifndef SMARTHOME_API_CLIENT_REMOTEMEDIASOURCE_H_
#define SMARTHOME_API_CLIENT_REMOTEMEDIASOURCE_H_
#include <SHBaseRemoteResource.h>

namespace OIC
{
    namespace Service
    {
        namespace SH
        {
            enum MediaSourceType
            {
                AUDIO, VIDEO, AUDIO_VIDEO
            };

            typedef struct
            {
                std::string name;
                int number;
                MediaSourceType type;
                bool status;
            } MediaSource;

            class RemoteMediaSourceResourceDelegate
            {
            public:
                virtual ~RemoteMediaSourceResourceDelegate () {}
                virtual void onGetMediaSource(std::list<MediaSource> sources) = 0;
                virtual void onChangeMediaSource(std::list<MediaSource> sources) = 0;
            };

            class RemoteMediaSourceResource: public SHBaseRemoteResource,
                    public SHBaseRemoteResourceDelegate
            {
            public:
                virtual ~RemoteMediaSourceResource();

                void getMediaSources();
                void changeMediaSources(std::list<MediaSource> sources);
                void setDelegate(RemoteMediaSourceResourceDelegate *delegate);

            protected:
                RemoteMediaSourceResource();

            private:
                virtual void onGet(PropertyBundle bundle, ResultCode ret);
                virtual void onSet(PropertyBundle bundle, ResultCode ret);

            private:
                RemoteMediaSourceResourceDelegate *m_delegate;
            };
        }
    }
}
#endif /* SMARTHOME_API_CLIENT_REMOTEMEDIASOURCE_H_ */
