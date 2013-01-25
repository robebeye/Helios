#include <Component/RespondsToKeyboardComponent.h>
#include <glm/glm.hpp>
namespace helios
{
    RespondsToKeyboardComponent::RespondsToKeyboardComponent(IEntity& owner) : BaseComponent(owner)
    {
        
    }
    RespondsToKeyboardComponent::~RespondsToKeyboardComponent()
    {
        
    }
    void 
    RespondsToKeyboardComponent::Update(uint64_t t) 
    {
        auto & events = mOwner.GetOwner()->GetEvents(e::kEventTargetKeyboard);
        
        for ( auto it = events.begin() ; it != events.end() ; ++it )
        {
            auto k = HEvent<KeyEvent>::GetData((*it));
            
            if((*it)->GetName() == e::kEventKeyDown)
            {
                
                //D_PRINT("-> Got key: %d\n",k.keyCode);
               
                mCurrentKeys.push_back(k.keyCode);
            }
            else if((*it)->GetName() == e::kEventKeyUp)
            {
                
                auto it = std::find(mCurrentKeys.begin(),mCurrentKeys.end(),k.keyCode);
                
                mCurrentKeys.erase(it);
            }
        }
        
    }
    void 
    RespondsToKeyboardComponent::Process()
    {
        
    }
    void 
    RespondsToKeyboardComponent::DispatchEvents()
    {
        // todo: create remapping system for actions
        
        glm::vec3 v(0.,0.,0.);
        
        for ( auto it = mCurrentKeys.begin() ; it != mCurrentKeys.end() ; ++it)
        {
            int k = (*it);

            std::string action = helios::SceneManager::Inst().GetConfiguration().GetActionForKey(k) ;

            boost::shared_ptr<HEvent<const char> > p ( new HEvent<const char>(e::kEventTargetAction, action, 0));
  
            mOwner.PushEvent(e::kEventTargetAction, p);
        }
        if(!(v.x == 0. && v.y == 0. && v.z == 0.) && mCurrentKeys.size() > 0) {
            v = glm::normalize(v);
        

        }
    }
}